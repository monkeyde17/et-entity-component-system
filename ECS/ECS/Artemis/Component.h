#ifndef COMPONENT_H
#define COMPONENT_H

namespace artemis
{
    /**
     * 组件，包含数据
     * 所有对象数据必须继承自该类 
     */
    class Component
    {
    public:
        virtual ~Component() = 0;
        
    protected:
        Component();
    };
    
};

#endif
