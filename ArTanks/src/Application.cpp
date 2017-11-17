#include "Application.h"
#include "utilities.h"
#include "ResourceIdentifiers.h"

void Application::run()
{
	//создание окна приложения
    mainWindow.create(sf::VideoMode(windowWidth, windowHeight),"ArTanks");
    //установка частоты кадров
    mainWindow.setFramerateLimit(120);
    //установка режима вертикальной синхронизации
    mainWindow.setVerticalSyncEnabled(false);
    //запуск таймера
    sf::Clock frameTimer;
    //установка состояния приложения
    changeState(TitleScreenState);
    currentState->reset();
    // цикл приложения
    while(mainWindow.isOpen())
    {
        sf::Event event;
        //проверка, что не нажата клавиша esc
        while(mainWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                mainWindow.close();
                return;
            }
            else
                currentState->passEvent(event); //если другое событие
        }
        //проверка нажатия клавиш управления танком
        currentState->passEvent(event);
        //очистка экрана окна
        mainWindow.clear(sf::Color::White);
        //отрисовка всех элементов мира
        currentState->draw(mainWindow);
        //отображение нового кадра в окне
        mainWindow.display();
        //засечка времени
        sf::Time dt = frameTimer.getElapsedTime();
        //рестарт таймера
        frameTimer.restart();
        //запуск проверки событий
        currentState->update(dt.asSeconds());
    }
}

//выход из приложения
void Application::quit(const std::string& error)
{
    if(error != "none")
        std::cerr << error << std::endl;
    mainWindow.close();
}
sf::Texture& Application::getTexture(TextureIdentifier id)
{
    if(!ResourcesLoaded)
        loadResources();
    return textureMgr.get(id);
}
sf::Font& Application::getFont(FontIdentifier id)
{
    if(!ResourcesLoaded)
        loadResources();
    return fontMgr.get(id);
}
void Application::loadResources()
{
    if(ResourcesLoaded)
        return;
    if( !(textureMgr.load(TankTexture,"../texture/tank.png") &&
    textureMgr.load(TurretTexture,"../texture/turret.png") &&
    textureMgr.load(ExplosionA,"../texture/ExplosionAsmall.png") &&
    textureMgr.load(TurretTarget,"../texture/target.png") &&
    textureMgr.load(ArrowDownSpriteSheet,"../texture/arrowdown.png") &&
    textureMgr.load(TitleBg,"../texture/BG.png") &&
    fontMgr.load(Purisa,"../texture/Purisa.ttf") &&
    fontMgr.load(UbuntuCondensed,"../texture/Purisa.ttf")) )
        throw std::runtime_error("failed to load resources");
    else
        ResourcesLoaded = true;
}
//смена режима приложения
void Application::changeState(AppStateType as)
{
    statesStack.push_back(as);
    currentState = getState(as);
}

//запросить информацию о выбранном режиме
AppState* Application::getState(AppStateType as)
{
    switch(as)
    {
    case TitleScreenState:
       return &titleState;
    case GameState:
        return &mGame;
    case GameOverState:
        return &mGameOver;
    }
    return nullptr;
}
TextureManager Application::textureMgr;
FontManager Application::fontMgr;
bool Application::ResourcesLoaded{false};
std::deque<AppStateType> Application::statesStack;
sf::RenderWindow Application::mainWindow;
Game Application::mGame;
GameOverScreen Application::mGameOver;
TitleScreen Application::titleState;


AppState* Application::currentState;
int main()
{
    srand(time(NULL));
    //запуск приложения
    Application::run();
    return EXIT_SUCCESS;
}
