//
//  main.cpp
//  test 
//
//  Created by etond on 14/10/24.
//  Copyright (c) 2014年 etond. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "Artemis/Artemis.h"

class VelocityComponent : public artemis::Component
{
public:
    float velocityX;
    float velocityY;
    
    VelocityComponent(float velocityX, float velocityY)
    {
        this->velocityX = velocityX;
        this->velocityY = velocityY;
    };
};

class PositionComponent : public artemis::Component
{
    
public:
    float posX;
    float posY;
    PositionComponent(float posX, float posY)
    {
        this->posX = posX;
        this->posY = posY;
    };
};


class MovementSystem : public artemis::EntityProcessingSystem
{
private:
    artemis::ComponentMapper<VelocityComponent> velocityMapper;
    artemis::ComponentMapper<PositionComponent> positionMapper;
    
public:
    MovementSystem()
    {
        addComponentType<VelocityComponent>();
        addComponentType<PositionComponent>();
    };
    
    virtual void initialize()
    {
        velocityMapper.init(*world);
        positionMapper.init(*world);
    };
    
    virtual void processEntity(artemis::Entity &e)
    {
        positionMapper.get(e)->posX += velocityMapper.get(e)->velocityX * world->getDelta();
        positionMapper.get(e)->posY += velocityMapper.get(e)->velocityY * world->getDelta();
    };
    
};

int main(int argc, char **argv)
{
    artemis::World world;
    artemis::SystemManager * sm = world.getSystemManager();
    MovementSystem * movementsys = (MovementSystem*)sm->setSystem(new MovementSystem());
    artemis::EntityManager * em = world.getEntityManager();
    
    sm->initializeAll();
    
    artemis::Entity & player = em->create();
    
    player.addComponent(new VelocityComponent(2,4));
    player.addComponent(new PositionComponent(0,0));
    player.refresh();
    
    PositionComponent * comp = (PositionComponent*)player.getComponent<PositionComponent>();
    
    while(true)
    {
        world.loopStart();
        world.setDelta(0.0016f);
        movementsys->process();
        
        std::cout << "X:"<< comp->posX << std::endl;
        std::cout << "Y:"<< comp->posY << std::endl;
    
        sleep(160);
    }
    
    return 0;
}
