#ifndef WORLD_H
#define WORLD_H


#include "ImmutableBag.h"
#include "TagManager.h"
#include "GroupManager.h"

namespace artemis
{
    class Entity;
    class EntityManager;
    class SystemManager;
    
    /**
     * 该框架主要的实例对象，包括所有的管理类
     *
     * 必须用该类去创建，删除，查找对象
     *
     * 在游戏主循环前初始化和设置游戏主循环的每次迭代的时间间隔也十分重要
     */
    class World
    {
    public:
        World();
        ~World();
        SystemManager * getSystemManager();
        EntityManager * getEntityManager();
        TagManager *   getTagManager();
        GroupManager * getGroupManager();
        float getDelta();
        void setDelta(float delta);
        void deleteEntity(Entity& e);
        void refreshEntity(Entity& e);
        Entity& createEntity();
        Entity& getEntity(int entityId);
        void loopStart();
        
    private:
        SystemManager * systemManager;
        EntityManager * entityManager;
        TagManager * tagManager;
        GroupManager * groupManager;
        float delta;
        Bag<Entity*> refreshed;
        Bag<Entity*> deleted;
    };
};
#endif // $(Guard token)
