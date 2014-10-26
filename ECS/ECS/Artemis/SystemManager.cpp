#include "SystemManager.h"
#include "World.h"
#include "EntitySystem.h"
#include "SystemBitManager.h"

namespace artemis
{
    
    SystemManager::SystemManager(World& world)
    {
        this->world = &world;
    }
    
    Bag<EntitySystem*> & SystemManager::getSystems()
    {
        return bagged;
    }
    
    void SystemManager::initializeAll()
    {
        for(int i=0; i< bagged.getCount(); i++)
        {
            bagged.get(i)->initialize();
        }
    }
    
    EntitySystem* SystemManager::setSystem(EntitySystem* stm)
    {
        bool bitFlag = false;
        int index = 0;
        
        /* 检查系统是否存在 */
        for(int i=0; i< bagged.getCount(); i++)
        {
            if(typeid(*stm) == typeid(*bagged.get(i)))
            {
                bitFlag = true;
                index = i;
            }
        }
        
        /* 若系统存在，则检查是否该系统和要设置的系统是同一个 */
        if(bagged.get(index) != stm)
        {
            /* 若系统已经存在，则释放要设置的系统 */
            if(bitFlag)
            {
                delete stm;
                /* 将已存在的系统返回 */
                stm = bagged.get(index);
            }
            /* 系统不存在，则添加系统到系统管理中 */
            else
            {
                stm->setWorld(world);
                systems[&typeid(*stm)]  = stm;
                bagged.add(stm);
                stm->setSystemBit(SystemBitManager::getBitFor(typeid(*stm)));
            }
        }
        
        return stm;
    }
    
    SystemManager::~SystemManager()
    {
        systems.clear();
        bagged.deleteData();
        bagged.clear();
    }
};
