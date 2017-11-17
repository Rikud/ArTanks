#ifndef Tank_H
#define Tank_H
#include "Application.h"
#include "utilities.h"
#include "WorldObject.h"
class Player;
class Tank : public WorldObject
{
public:
    Tank();
    ~Tank();
    void draw(sf::RenderTarget &target);
    void step(float dt);
    void handleCollision(WorldObject &b);
    void reset();
    void setMovement(int val);
    void setPosition(const sf::Vector2f& pos);
    void setPosition(int x,int y) { setPosition(sf::Vector2f(x,y)); }
    friend class Player;
    void setPlayer(Player *p);
    Player &getPlayer() { return *myOwner;  }
    void weapAct(float dlife);
    sf::Sprite& getTankSpr(){ return tank; }
    sf::Sprite& getTurretSpr(){ return turret; }
    sf::RectangleShape getTankRect();
    void startReload();
private:
    void setLifeFill(int l);
    sf::Texture tankTexture;
    sf::Texture turretTexture;
    Player *myOwner;
    int moving;//on land
    sf::Sprite tank;
    sf::Sprite turret;
    bool freefall;
    sf::Vector2f velocity;
    bool readyToFire;
    float reloadTimer;
    bool fadingLife;
    float fadingTimer;//fading starts after this runs out
};

#endif // Tank_H
