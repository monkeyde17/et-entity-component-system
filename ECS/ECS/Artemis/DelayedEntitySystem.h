#ifndef DELAYED_ENTITY_SYSTEM_H
#define DELAYED_ENTITY_SYSTEM_H

#include "EntitySystem.h"

namespace artemis
{
    /**
     * 实体延迟系统
     */
    class DelayedEntitySystem : public EntitySystem
    {
    public:
        DelayedEntitySystem();
        
        /* 延迟指定时间开始 */
        void start(float delay);
        
        /* 直接运行 */
        void runNow();
        
        /* 停止运行 */
        void stop();
        
        /* 是否重复 */
        void setAutoRepeat(bool repeat);
        
        float getInitialTimeDelay();
        float getRemainingTime();
        bool isRunning();
        
    protected:
        virtual void processEntities(ImmutableBag<Entity*> & bag);
        virtual void processEntities(ImmutableBag<Entity*> & bag, float accumulatedDelta) = 0;
        virtual bool checkProcessing();
        
    private:
        float delay;
        float acc;
        bool running;
        bool autoRepeat;
    };
};

#endif // $(Guard token)
