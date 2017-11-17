#include "GameOverScreen.h"
#include "Application.h"

GameOverScreen::GameOverScreen() :
    AppState(GameOverState),
    bg(Application::getTexture(TitleBg)),
    message("",Application::getFont(Purisa)),
    gameOverText("Game Over!",Application::getFont(Purisa))
{
    message.setColor(sf::Color::Black);
    gameOverText.setColor(sf::Color::White);
    gameOverText.setCharacterSize(110);
    message.setCharacterSize(20);
    gameOverText.setOrigin(gameOverText.getLocalBounds().width/2,gameOverText.getLocalBounds().height/2);
}
void GameOverScreen::reset()
{
    sf::RenderWindow &win = Application::getWindow();
    gameOverText.setPosition(win.getSize().x/2,2*gameOverText.getCharacterSize());
    message.setOrigin(message.getLocalBounds().width/2,message.getLocalBounds().height/2);
    message.setPosition(gameOverText.getPosition().x,gameOverText.getPosition().y
                        + gameOverText.getLocalBounds().height + message.getCharacterSize());
}
void GameOverScreen::draw(sf::RenderWindow &window)
{
    window.draw(bg);
    window.draw(gameOverText);
    window.draw(message);
}
void GameOverScreen::update(float dt){}
void GameOverScreen::passEvent(sf::Event Event)
{
    if(Event.type == sf::Event::KeyPressed || Event.type == sf::Event::MouseButtonReleased)
        Application::changeState(GameSetupState);
}
