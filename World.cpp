#include "World.h"
#include "Land.h"
#include "Tank.h"
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
    case WorldObject::TankType:
		obj.reset(new Tank());
		break;
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

//запуск проверки всех событий
void World::stepAll(float dt)
{
    timer += dt;
    while(timer > updateRate)
    {
        timer -= updateRate;
        //crudeStepAll(updateRate);
        for(auto objit = objects.begin();objit != objects.end();)
		{
			//перебор всех остальных объектов
			for(auto j = std::next(objit) ; j != objects.end() ; ++j)
				//проверка взаимодействий объектов
				(*objit)->handleCollision(*(*j).get());
				(*objit)->step(updateRate);
				++objit;
		}
    }
}

void World::play()
{
    for(auto &objit : objects)
        objit->reset();
    timer = 0;
}
