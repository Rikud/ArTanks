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

float Land::getNormAngle(int x,int y)
{
    //Calculate the weighted average of the solid pixels to get the normal
    float avgX = 0,avgY = 0;
    int sq = 3;//size of the square to calculate the average
    for(int w = -sq; w <= sq; w++)
    {
      for(int h = -sq; h <= sq; h++)
      {
        if(isPixelSolid(x + w, y + h))
        {
          avgX -= w;
          avgY -= h;
        }
      }
    }
//    float slope = (-hmap[x-sq]+hmap[x+sq])/-float(sq);
//    float slope2 =(-hmap[x-sq]+hmap[x+sq])/-float(sq+1);
//    std::cout << "Angles :\n\t" << TO_DEG(arctan(1.f,slope)) << "\n\t" << TO_DEG(arctan(1.f,slope2)) << "\n\t" << TO_DEG(arctan(slope,1.f)) << "\n\t";
//    std::cout << "Correct : " << TO_DEG(arctan(-avgY,avgX)) << std::endl;
//    return arctan(1.f,slope2);
    return arctan(-avgY,avgX);
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
	 switch(b.type)
	    {
	    case TankType:
	        b.handleCollision(*this);
	    case WeaponType:
	        b.handleCollision(*this);
	        break;
	    default:
	        break;
	    }
}

void Land::step(float dt) {

}

void Land::destroyCircle(int x0, int y0, int radius)
{
    int x = 0 , y = radius;
    int sqradius = radius*radius;
    while( x < radius )
    {
        destroyColumn(x0+x,y0-y,y0+y);
        destroyColumn(x0-x,y0-y,y0+y);
        ++x;
        y = cachedSqrt(sqradius-x*x)+0.5;
    }
}

void Land::destroyColumn(int x,int top,int bottom)
{
    if(!isInWindow(x,0))
        return;
    int LandTop = windowHeight-hmap[x];
    bottom = std::min(bottom,windowHeight-1);
    top = std::max(0,top);
    if(bottom > LandTop)
    {
    // We have two cases ,
        // case 1 the part is inside the Land , making a cavity
        if(top > LandTop)
        {
            for(int iy = top; iy <= bottom ; ++iy)
                LandImg.setPixel(x,iy,sf::Color::Transparent);
            std::list<slManifest> &slColList = slColumns[x];
            slManifest cav{top,bottom,60};
            for(auto i = slColList.begin() ;;) //insert the cavity appropriately into the list
            {
                if(cav.dest < i->src || i == slColList.end())
                {
                    slColList.insert(i,cav);
                    break;
                }
                if(i->intersects(cav)) //then merge i to cav and continue with the new i
                {
                    cav.merge(*i);
                    i = slColList.erase(i);
                }
                else ++i;
            }
        }
        // case 2 the part is on the surface , it makes a crater
        else
        {
            for(int iy = LandTop; iy <= bottom ; ++iy)
                LandImg.setPixel(x,iy,sf::Color::Transparent);
            hmap[x] = windowHeight-bottom;
        }
        hmap[x] = std::max(hmap[x],0);
        LandModified = true;
    }
}

bool Land::isPixelSolid(int x,int y)
{
    if(isInRange(size_t(x),size_t(0),hmap.size()))
        return LandImg.getPixel(x,y) != sf::Color::Transparent;
    return true;//outside the window consider the pixels  to be solid
}
