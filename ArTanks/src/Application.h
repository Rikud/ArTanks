#ifndef APPLICATION_H
#define APPLICATION_H
#include <deque>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "ResourceManager.h"
#include "TitleScreen.h"
#include "GameOverScreen.h"
#include "utilities.h"
#include "AppState.h"

class Application
{
public:
    Application() = delete;
    static sf::RenderWindow& getWindow(){ return mainWindow;  }
    static sf::Texture& getTexture(TextureIdentifier id);
    static sf::Font& getFont(FontIdentifier id);
    static AppStateType getCurrentStateType() { return statesStack.back(); }
    static void changeState(AppStateType as);
    static void loadResources();
    static void run();
    static void quit(const std::string& error = "none");
    static Game& getGame(){ return mGame; }
private:

    static TextureManager textureMgr;
    static FontManager fontMgr;
    static bool ResourcesLoaded;
    static AppState* getState(AppStateType as);
    static std::deque<AppStateType> statesStack;
    static sf::RenderWindow mainWindow;
    static Game mGame;
    static GameOverScreen mGameOver;
    static TitleScreen titleState;
    static AppState* currentState;
};

#endif // APPLICATION_H
