#include "Game.h"

Game::Game() :
    AppState(GameState),
    land(nullptr),
	  player(nullptr),
	  counter(0)
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
    this->addPlayer();
    world.play();
    Application::getWindow().setMouseCursorVisible(false);
}

void Game::addPlayer() {
	Tank* pTank = static_cast<Tank*>(world.addObj(WorldObject::TankType));
	Sight* pSight = static_cast<Sight*>(world.addObj(WorldObject::SightType));
	this->player = new Player(pTank, pSight);
	int x = rand() % (windowWidth - 20) + 10;
	pTank->setPosition(sf::Vector2f(x,windowHeight-getLandHeight(x)-10));
	pTank->setPlayer(this->player);
	pSight->setPlayer(this->player);
}

void Game::draw(sf::RenderWindow &window)
{
    world.drawAll(window);
}
//обновление событий
void Game::update(float dt)
{
	world.stepAll(dt);
}
void Game::passEvent(sf::Event Event)
{
	if(Event.type == sf::Event::KeyPressed && this->player->getTankMove() == 0)
	{
		switch(Event.key.code)
		{
		case sf::Keyboard::Left:
			this->player->moveTank(-1);
			break;
		case sf::Keyboard::Right:
			this->player->moveTank(1);
			break;
		}
	}
	else if(Event.type == sf::Event::KeyReleased && (Event.key.code == sf::Keyboard::Left || Event.key.code == sf::Keyboard::Right)) {
		this->player->moveTank(0);
	}
	else if(Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Left) {
		this->player->fire();
	}
	else if (Event.type == sf::Event::MouseMoved) {
		this->player->moveCursor();
	}
}
