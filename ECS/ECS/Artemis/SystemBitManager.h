#ifndef SYSBITMANAGER_H
#define SYSBITMANAGER_H

#include <bitset>
#include <map>
#include "TypeInfoComparator.h"
#include "BitSize.h"

namespace artemis
{
    
    class EntitySystem;
    
    class SystemBitManager
    {
    public:
        
        static std::bitset<BITSIZE> & getBitFor(const std::type_info & type);
        static void removeBitSets();
        
        /* 这里定义的模板类 */
        template<typename system>
        static std::bitset<BITSIZE> & getBitFor()
        {
            //assert((std::is_base_of< EntitySystem, system >::value == true));
            return getBitFor(typeid(system));
        }
        
    private:
        /* 静态变量，实则管理bitset的一个类变量 */
        static int POS;
        
        /* 这里的map自定义了比较函数 */
        static std::map< const std::type_info*, std::bitset<BITSIZE>*, type_info_comparator > systemBits;
        
    };
    
};
#endif // $(Guard token)
