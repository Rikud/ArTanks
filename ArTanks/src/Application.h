#ifndef APPLICATION_H
#define APPLICATION_H
#include <deque>
#include <string>
#include <SFML/Graphics.hpp>
#include "utilities.h"
#include "AppState.h"
class Game;
class Application
{
public:
    Application() = delete;
    static sf::RenderWindow& getWindow(){ return mainWindow;  }
    static AppStateType getCurrentStateType() { return statesStack.back(); }
    static void changeState(AppStateType as);
    static void run();
    static void quit(const std::string& error = "none");
    static Game& getGame(){ return mGame; }
private:
    static AppState* getState(AppStateType as);
    static std::deque<AppStateType> statesStack;
    static sf::RenderWindow mainWindow;
    static Game mGame;
    static AppState* currentState;
};

#endif // APPLICATION_H
