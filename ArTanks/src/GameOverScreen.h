#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H
#include "AppState.h"

class GameOverScreen : public AppState
{
    public:
        GameOverScreen();
        void reset();
        void draw(sf::RenderWindow &window);
        void update(float dt);
        void passEvent(sf::Event Event);
    private:
        sf::Sprite bg;
        sf::Text message;
        sf::Text gameOverText;
};

#endif // GAMEOVERSCREEN_H
