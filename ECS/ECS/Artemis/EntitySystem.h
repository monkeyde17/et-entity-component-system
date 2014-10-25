#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include <bitset>
#include "BitSize.h"
#include "Component.h"
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <bitset>
#include "ImmutableBag.h"
//#include "Entity.h"
#include "ComponentTypeManager.h"


namespace artemis
{
    
    class Entity;
    class World;
    
    /**
     * The most raw entity system. It should not typically be used, but you can create your own
     * entity system handling by extending this. It is recommended that you use the other provided
     * entity system implementations.
     */
    class EntitySystem
    {
    public:
        virtual ~EntitySystem() { world = NULL; }
        
    public:
        void printTypeFlag() { std::cout << typeFlags; }
        std::bitset<BITSIZE> getSystemBit() { return systemBit; }
        
        void setSystemBit(std::bitset<BITSIZE> bit);
        void setWorld(World *world);
        void change(Entity &e);
        void process();
        int getEntityCount();
        
        /* override these functions */
        virtual void initialize() {};
        
    protected:
        EntitySystem() { this->world = NULL; };
        
        /**
         * Call this in the constructor of the derived system
         */
        template<typename component_type>
        void addComponentType()
        {
            //Add Bits to typeflags
            typeFlags |= ComponentTypeManager::getBit<component_type>();
        }
        
        /* override these functions */
        virtual void begin() {};
        virtual void end() {};
        virtual void removed(Entity &e) {};
        virtual void added(Entity &e) {};
        
        //Abstracts
        virtual void processEntities(ImmutableBag<Entity*> & bag) = 0;
        virtual bool checkProcessing() = 0;
        
    private:
        void remove(Entity &e);
        
    protected:
        World *world;
        
    private:
        std::bitset<BITSIZE> systemBit;
        std::bitset<BITSIZE> typeFlags;
        Bag<Entity*> actives;
    };
    
};


#endif
