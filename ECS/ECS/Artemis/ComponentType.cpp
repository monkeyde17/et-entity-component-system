#include "ComponentType.h"

namespace artemis
{
    std::bitset<BITSIZE> ComponentType::nextBit(1);
    int ComponentType::nextId = 1;
    
    ComponentType::ComponentType()
    {
        init();
    }
    
    void ComponentType::init()
    {
        bit = nextBit;
        nextBit = nextBit << 1;
        id = nextId++;
    }
    
    std::bitset<BITSIZE> ComponentType::getBit() const
    {
        return bit;
    }
    
    int ComponentType::getId() const
    {
        return id;
    }
    
    void ComponentType::reset()
    {
        nextBit = 1;
        nextId = 1;
    }
    
};
