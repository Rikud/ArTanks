#ifndef GAME_H
#define GAME_H
#include "World.h"
#include "Land.h"
#include "AppState.h"
#include "Player.h"
#include "Bot.h"
#include "BotII.h"
#include "utilities.h"
#include "Application.h"
#include <vector>

class Game : public AppState
{
public:
    Game();
    ~Game();
    void draw(sf::RenderWindow &window);
    void update(float dt);
    void passEvent(sf::Event Event);
    void reset();
    inline void incCounter() { ++counter; }
    inline void decCounter() { --counter;}
    void newGame(int n_players = 2, Land::Landtype land_t = Land::Random);
    void addPlayer();
    void addBot();
    inline int getLandHeight(int x){ return land->getHeight(x); }
    inline float getLandNormAng(int x,int y){ return land->getNormAngle(x,y); }
    inline Player* getPlayer() {return this->player;}
    Land* getLand() {return this->land;}
    WorldObject* addWorldObj(WorldObject* wo){ return world.addObj(wo); }
private:
    int counter; //weapons,effects,tanks on free fall etc. counter
    Land *land;
    World world;
    Player* player;
    BotII* botII;
};

#endif // GAME_H
