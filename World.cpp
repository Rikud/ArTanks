#include "World.h"
#include "Land.h"
#include <iostream>

World::World() : timer(0) { }

WorldObject* World::addObj(WorldObject* optr)
{
    objects.push_back(WorldObjectptr(optr));
    return optr;
}
WorldObject* World::addObj(WorldObject::Type t)
{
    WorldObjectptr obj;
    bool playNice = true;
    switch(t)
    {

    case WorldObject::LandType:
        obj.reset(new Land());
        break;
    default:
        playNice = false;
    }
    if(playNice)
    {
        objects.push_back(std::move(obj));
        return objects.back().get();
    }
    return nullptr;
}
void World::removeObj(std::list<WorldObjectptr>::iterator o)
{
    objects.erase(o);
}
void World::drawAll(sf::RenderWindow &win)
{
    for(auto &objit : objects)
        objit->draw(win);
}

void World::play()
{
    for(auto &objit : objects)
        objit->reset();
    timer = 0;
}
