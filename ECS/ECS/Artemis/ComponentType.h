#ifndef COMPTYPE_H
#define COMPTYPE_H

#include <bitset>
#include "BitSize.h"

namespace artemis
{
    /**
     * 组件类型，即组件的Id和Bit位
     * 该类需要通过ComponentTypeManager来管理
     * 不能自己声明并实例化对象
     */
    class ComponentType
    {
    public:
        ComponentType();
        
        std::bitset<BITSIZE> getBit() const;
        int getId() const;
        
        /* 重置静态变量 */
        static void reset();
        
    private:
        /* 初始化 */
        void init();
        
    private:
        /* 组件Bit */
        std::bitset<BITSIZE> bit;
        /* 组件Id */
        int id;
        
    private:
        /* 类变量，下个组件Bit */
        static std::bitset<BITSIZE> nextBit;
        /* 类变量，下个组件Id */
        static int nextId;
    };
};
#endif // $(Guard token)
