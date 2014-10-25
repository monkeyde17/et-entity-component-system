#ifndef GROUP_MANAGER_H
#define GROUP_MANAGER_H

#include "ImmutableBag.h"
#include <map>
#include <string>

namespace artemis
{
    class Entity;
    
    /**
     * 如果你需要将你的实体分组，例如坦克实体分配到单元组，爆炸实体分配到效果组。
     * 那么你必须使用World的实例化对象来获得该类的实例化对象
     */
    class GroupManager
    {
    public:
        GroupManager();
        ~GroupManager();
        
        void set(std::string group, Entity& e);
        void remove(Entity& e);
        
        std::string getGroupOf(Entity& e);
        bool isGrouped(Entity& e);
        bool isInGroup(std::string group, Entity& e);
        
        /* 根据分组查询实体，若没找到则创建该分组 */
        ImmutableBag<Entity*>* getEntities(std::string group);
        
    private:
        Bag<Entity*> empty_bag;
        std::string empty_string;
        Bag<std::string*> groupByEntity;
        std::map<std::string, Bag<Entity*>*> entitiesByGroup;
    };
};

#endif // $(Guard token)