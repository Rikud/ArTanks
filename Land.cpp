#include "Land.h"
#include "utilities.h"
#include "simplexnoise.h"


Land::Land() :
    WorldObject(LandType),
    LandModified(false),
    hmap(windowWidth),
    LandSpr(),
    LandImg(),
    LandTexture()
{
    LandImg.create(windowWidth, windowHeight, sf::Color::Transparent);
}

void Land::draw(sf::RenderTarget &target)
{
    if(LandModified)
    {
        LandTexture.loadFromImage(LandImg);
        LandModified = false;
    }
    target.draw(LandSpr);
}
void Land::reset()
{
    hmap.resize(windowWidth);
}
int Land::getHeight(int x)
{
    if(x >= 0 && x < int(hmap.size()))
    {
        return hmap[x];
    }
    return 0;
}

void Land::genHeightMap(Landtype Land_t)
{
    Land_t = Hilly;

    int octaves, llim = 0, ulim = windowHeight;
    double persistance, scale, detail;
    switch(Land_t)
    {

    case Hilly:
        octaves = 4;
        persistance = 0.4;
        scale = 1;
        detail = windowWidth / 3.0;
        break;
}
    LandImg.create(LandImg.getSize().x,LandImg.getSize().y,sf::Color::Transparent);
   double offsetx = (rand() % 1000);
  double y = rand() % 1000;
    for(int i = 0; i < windowWidth; i++)
    {
        hmap[i] = scaled_octave_noise_2d(octaves, persistance, scale, llim, ulim, double(i + offsetx) / detail, y / detail);
        for(int h = windowHeight - hmap[i]; h < windowHeight ; ++h)
        {
            LandImg.setPixel(i, h, grad(double(windowHeight - h) / (hmap[i]),
                                        sf::Color(150, 155, 0), sf::Color(50, 150, 50)));
        }
    }
    LandTexture.loadFromImage(LandImg);
    LandSpr.setTexture(LandTexture);
}
void Land::handleCollision(WorldObject &b)
{
//
}

bool Land::isPixelSolid(int x,int y)
{
    if(isInRange(size_t(x),size_t(0),hmap.size()))
        return LandImg.getPixel(x,y) != sf::Color::Transparent;
    return true;//outside the window consider the pixels  to be solid
}
