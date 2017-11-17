#ifndef Land_H
#define Land_H
#include "WorldObject.h"
#include <vector>
#include <list>
#include "utilities.h"

struct slManifest //sliding columns information structure
{
    int src,dest; //describes the cavity in the range [src,dest)
    double velocity;
    void inline merge(slManifest b)
    {
        src = std::min(b.src,src);
        dest = std::max(b.dest,dest);
    }
    bool inline intersects(slManifest b)
    {
        slManifest *minRange = (dest-src < b.dest-b.src)?this:&b;
        slManifest *maxRange = (dest-src > b.dest-b.src)?this:&b;
        if(isInRange(minRange->src,maxRange->src,maxRange->dest))
            return true;
        if(isInRange(minRange->dest,maxRange->src,maxRange->dest))
            return true;
        return false;
    }
};

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
    void destroyCircle(int x0, int y0, int radius);
    void destroyColumn(int x,int top,int bottom);
    bool LandModified;

private:
    std::map<int,std::list<slManifest>> slColumns;
    bool isPixelSolid(int x,int y);
    std::vector<int> hmap;
    sf::Sprite LandSpr;
    sf::Image LandImg;
    sf::Texture LandTexture;
};

#endif // Land_H
