#include "TitleScreen.h"
#include "Application.h"
#include "utilities.h"

TitleScreen::TitleScreen()  :
    AppState(TitleScreenState),
    bg(Application::getTexture(TitleBg)),
    mainMenu(Application::getFont(Purisa),40)
{
    mainMenu.add("Meow",sf::Color::White);
    mainMenu.add("Exit",sf::Color::White);
    mainMenu.setSelectionBgColor(sf::Color(0,0,0,100));
    mainMenu.create(windowWidth,0);
    mainMenu.setPosition(0,300);
}

TitleScreen::~TitleScreen()
{
    //dtor
}
void TitleScreen::reset()
{}
void TitleScreen::draw(sf::RenderWindow &window)
{
    window.draw(bg);
    mainMenu.draw(window);
}
void TitleScreen::update(float dt)
{
    mainMenu.step(dt);
    int query = mainMenu.querySelecion();
    if(query >= 0)
    {
        switch(query)
        {
        case 0://Play
            Application::changeState(GameState);
            Application::getGame().newGame(2,static_cast<Land::Landtype>(0));
            break;
        case 1://Exit
            Application::quit();
            break;
        default:
            PRINT_VAR(query)
            break;
        }
    }
}
void TitleScreen::passEvent(sf::Event event)
{
    mainMenu.passEvent(event);
}
