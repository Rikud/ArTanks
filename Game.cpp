
#include "Application.h"
#include "utilities.h"
#include <cassert>

Game::Game() :
    AppState(GameState),
    land(nullptr)
{}
void Game::reset()
{
    newGame();
}
void Game::newGame(int n_players,Land::Landtype land_t)
{
    world.clear();

    land = static_cast<Land*>(world.addObj(WorldObject::LandType));
    land->genHeightMap(land_t);

    world.play();
}

void Game::draw(sf::RenderWindow &window)
{
    world.drawAll(window);
}
void Game::update(float dt)
{
  //
}
void Game::passEvent(sf::Event Event)
{
  //
}
