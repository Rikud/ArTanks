#include "Application.h"
#include "utilities.h"

void Application::run()
{
    mainWindow.create(sf::VideoMode(windowWidth, windowHeight),"A Game feat. Tanks");
    mainWindow.setFramerateLimit(120);
    mainWindow.setVerticalSyncEnabled(false);
    sf::Clock frameTimer;
    changeState(GameState);
    currentState->reset();
    while(mainWindow.isOpen())
    {
        sf::Event event;
        while(mainWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                mainWindow.close();
                return;
            }
            else
                currentState->passEvent(event);
        }
        mainWindow.clear(sf::Color::White);
        currentState->draw(mainWindow);
        mainWindow.display();
        sf::Time dt = frameTimer.getElapsedTime();
        frameTimer.restart();
        currentState->update(dt.asSeconds());
    }
}
void Application::quit(const std::string& error)
{
    if(error != "none")
        std::cerr << error << std::endl;
    mainWindow.close();
}

void Application::changeState(AppStateType as)
{
    statesStack.push_back(as);
    currentState = getState(as);
}
AppState* Application::getState(AppStateType as)
{
    switch(as)
    {
    case GameState:
        return &mGame;
    }
    return nullptr;
}

std::deque<AppStateType> Application::statesStack;
sf::RenderWindow Application::mainWindow;
Game Application::mGame;

AppState* Application::currentState;
int main()
{
    srand(time(NULL));
    Application::run();
    return EXIT_SUCCESS;
}
