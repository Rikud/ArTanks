#ifndef GAME_H
#define GAME_H
#include "World.h"
#include "Land.h"
#include "AppState.h"
#include <cassert>

class Game : public AppState
{
public:
    Game();
    void draw(sf::RenderWindow &window);
    void update(float dt);
    void passEvent(sf::Event Event);
    void reset();

    void newGame(int n_players = 2,Land::Landtype land_t = Land::Random);

    inline int getLandHeight(int x){ return land->getHeight(x); }

    WorldObject* addWorldObj(WorldObject* wo){ return world.addObj(wo); }

private:

    Land *land;
    World world;

};

#endif // GAME_H
