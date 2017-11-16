#include "Application.h"
#include "Game.h"

void Application::run()
{
	//создание окна приложения
    mainWindow.create(sf::VideoMode(windowWidth, windowHeight),"A Game feat. Tanks");
    //установка частоты кадров
    mainWindow.setFramerateLimit(120);
    //установка режима вертикальной синхронизации
    mainWindow.setVerticalSyncEnabled(false);
    //запуск таймера
    sf::Clock frameTimer;
    //установка состояния приложения
    changeState(GameState);
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
    //запуск приложения
    Application::run();
    return EXIT_SUCCESS;
}
