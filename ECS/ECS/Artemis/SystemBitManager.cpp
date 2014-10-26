#include "SystemBitManager.h"

namespace artemis
{
    /* 静态变量声明 */
    int SystemBitManager::POS = 0;
    
    /* 静态变量声明 */
    std::map< const std::type_info*, std::bitset<BITSIZE>*, type_info_comparator > SystemBitManager::systemBits;
    
    /* 删除改Entity分配的BitId */
    void SystemBitManager::removeBitSets()
    {
        std::map< const std::type_info*, std::bitset<BITSIZE>*, type_info_comparator >::iterator it;
        
        for(it = systemBits.begin(); it != systemBits.end(); it++)
        {
            delete it->second;
        }
        systemBits.clear();
        POS = 0;
    }
    
    /* 给新Entity分配BitId */
    std::bitset<BITSIZE> & SystemBitManager::getBitFor(const std::type_info & type)
    {
        std::bitset<BITSIZE> * bit = systemBits[&type];
        
        if(bit == NULL)
        {
            bit = new std::bitset<BITSIZE>(1);
            (*bit)  <<=  POS++;
            
            systemBits[&type] = bit;
        }
        return *bit;
    }
}
