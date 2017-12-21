#ifndef Tank_H
#define Tank_H

#include "Application.h"
#include "utilities.h"
#include "WorldObject.h"
class ControlEntity;
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
    friend class ControlEntity;
    void setOwner(ControlEntity *p);
    ControlEntity& getOwner() { return *myOwner;  }
    sf::Sprite& getTankSpr(){ return tank; }
    sf::Sprite& getTurretSpr(){ return turret; }
    sf::RectangleShape getTankRect();

    void weapAct(float dlife);
    void startReload();

private:
    void setLifeFill(int l);
    ControlEntity* myOwner;
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
