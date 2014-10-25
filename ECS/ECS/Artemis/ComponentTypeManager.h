#ifndef COMPTYPE_MANAGER_H
#define COMPTYPE_MANAGER_H

#include <assert.h>
#include <bitset>
#include "TypeInfoComparator.h"
#include "ComponentType.h"
#include "Component.h"
#include <map>

namespace artemis
{
    /**
     * 组件类型管理类：管理组件类型的Id和Bit 
     */
    class ComponentTypeManager
    {
    public:
        /* 查找组件类型，没找到就加入该组件类型 */
        static ComponentType & getTypeFor(const std::type_info &t);
        
        /* 删除所有组件类型 */
        static void deleteComponentTypes();
        
        /* 根据类型获得组件类型对象 */
        template<typename c>
        static ComponentType & getTypeFor()
        {
            return getTypeFor(typeid(c));
        }
        
        /* 根据类型获得组件类型Bit */
        template<typename c>
        static std::bitset<BITSIZE> getBit()
        {
            return getTypeFor(typeid(c)).getBit();
        }
        
        /* 根据类型获得组件类型Id */
        template<typename c>
        static int getId()
        {
            return getTypeFor(typeid(c)).getId();
        };
        
        //typedef getCompBit bitset<BITSIZE>(*getBit<Component>)();
        
    private:
        /* 类变量 */
        static std::map<const std::type_info*,ComponentType*,
        type_info_comparator> componentTypes;
    };
}

#endif // $(Guard token)
