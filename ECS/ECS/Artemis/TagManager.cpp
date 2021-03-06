#include "TagManager.h"
#include "Entity.h"

namespace artemis {
    
    TagManager::TagManager()
    {
    }
    
    Entity& TagManager::getEntity(const std::string tag)
    {
        return *tagByEntity[tag];
    }
    
    bool TagManager::isSubscribed(const std::string tag)
    {
        return (tagByEntity[tag] != NULL);
    }
    
    void TagManager::remove(Entity &e)
    {
        std::map<std::string, Entity*>::iterator it;
        for (it = tagByEntity.begin(); it != tagByEntity.end(); ++it)
        {
            if(it->second == &e)
            {
                tagByEntity.erase(it->first);
                return;
            }
        }
        
    }
    
    void TagManager::unSubscribe(const std::string tag)
    {
        //tagByEntity[tag] = NULL;
        tagByEntity.erase(tag);
    }
    
    void TagManager::subscribe(std::string tag, Entity &e)
    {
        remove(e);
        tagByEntity[tag] = &e;
    }
    
}
