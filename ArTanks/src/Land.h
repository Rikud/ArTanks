#ifndef Land_H
#define Land_H
#include "WorldObject.h"
#include <vector>
#include <list>
#include "utilities.h"

class Land : public WorldObject
{
public:
    Land();
    ~Land() = default;
    enum Landtype
    {
        Flats, //to do
       Valley, //
        Hilly, //
       Random, //
      TotalTypes //
    };
    float getNormAngle(int x,int y);
    void genHeightMap(Landtype Land_t);
    void draw(sf::RenderTarget &target);
    void reset();
    void handleCollision(WorldObject &b);
    int  getHeight(int x);
    void step(float dt);
    bool LandModified;

private:

    bool isPixelSolid(int x,int y);
    std::vector<int> hmap;
    sf::Sprite LandSpr;
    sf::Image LandImg;
    sf::Texture LandTexture;
};

#endif // Land_H
