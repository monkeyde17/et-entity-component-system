#ifndef TAG_MANAGER_H
#define TAG_MANAGER_H


#include <map>
#include <string>

namespace artemis
{
    class Entity;
    
    /**
     * 为实体打上标签，例如"Boss"
     */
    class TagManager
    {
    public:
        TagManager();
        void subscribe(const std::string tag, Entity &e);
        void unSubscribe(const std::string tag);
        bool isSubscribed(const std::string tag);
        Entity & getEntity(const std::string tag);
        void remove(Entity &e);
        
    private:
        std::map<std::string, Entity*> tagByEntity;
    };
};
#endif // $(Guard token)
