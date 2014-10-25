#ifndef D_E_PROCESSING_SYSTEM_H
#define D_E_PROCESSING_SYSTEM_H

#include "DelayedEntitySystem.h"

namespace artemis
{
    /**
     * @brief 实体延时处理系统
     * 
     * 比如说有一个生命系统会在一定时间后将实体对象释放，而不是去减小剩余时间的值。
     * 可以简单的在一段时间后直接执行该系统逻辑，然后重置该系统去处理下一个实体对象。
     *
     * 再比如有个帧动画系统，300毫秒后要给一个实体对象播放帧动画。
     * 那么可以在设置帧动画系统在300毫秒后播放该动画。
     * 
     * 这样可以节省CPU的资源
     */
    class DelayedEntityProcessingSystem : public DelayedEntitySystem
    {
    protected:
        virtual void processEntities(ImmutableBag<Entity*>& bag, float accumulatedDelta);
        virtual void processEntity(Entity& e, float accumulatedDelta) = 0;
    };
};

#endif // $(Guard token)
