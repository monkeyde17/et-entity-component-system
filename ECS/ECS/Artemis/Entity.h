#ifndef ENTITY_H
#define ENTITY_H

#include <bitset>
#include <string>
#include <cstddef>
#include <typeinfo>
#include "BitSize.h"
#include "ImmutableBag.h"
#include "EntityManager.h"
#include "ComponentTypeManager.h"

namespace artemis
{
    class Component;
    class ComponentType;
    class World;
    
    /**
     * 实体类
     *
     * 必须通过World类来实例化对象
     */
    class Entity
    {
    private:
        /* 非拷贝构造函数 */
        Entity(const Entity&);
        /* 非赋值操作 */
        Entity& operator=(const Entity&);
        
    public:
        Entity(World * world, int id);
        ~Entity();
        
        /* getter & setter */
        int getId();
        void setUniqueId(long int uniqueId);
        long int getUniqueId();
        
        /* 类型Bit */
        std::bitset<BITSIZE> getTypeBits();
        void addTypeBit(std::bitset<BITSIZE> bit);
        void removeTypeBit(std::bitset<BITSIZE> bit);
        void setTypeBits(std::bitset<BITSIZE> typeBits);
        
        /* 系统Bit */
        std::bitset<BITSIZE> getSystemBits();
        void addSystemBit(std::bitset<BITSIZE> bit);
        void removeSystemBit(std::bitset<BITSIZE> bit);
        void setSystemBits(std::bitset<BITSIZE> systemBits);
        
        
        void addComponent(Component * c);
        
        template<typename c>
        void removeComponent()
        {
            entityManager->removeComponent(*this,ComponentTypeManager::getTypeFor<c>());
        }
        
        void removeComponent(ComponentType & type);
        
        
        Component * getComponent(ComponentType & type);
        
        template<typename c>
        Component * getComponent()
        {
            return (c*)entityManager->getComponent(*this,ComponentTypeManager::getTypeFor<c>());
        }
        
        ImmutableBag<Component*> & getComponents();
        
        /* 重置Bit */
        void reset();
        
        bool isActive();
        void refresh();
        void remove();
        void setGroup(std::string group);
        void setTag(std::string tag);
        
        std::string toString();
    private:
        int id;
        long int uniqueId;
        std::bitset<BITSIZE> typeBits;
        std::bitset<BITSIZE> systemBits;
        World * world;
        EntityManager * entityManager;
    };
};
#endif // $(Guard token)
