#ifndef UTILITIES_INCLUDED
#define UTILITIES_INCLUDED
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#define LERP(t,a,b) ( (a) + (t) * ((b) - (a)) ) //liner interpolation
#define TO_RAD(x) ( (x)*M_PI/180.0 )
#define TO_DEG(x) ( (x)*180.0/M_PI )

#ifndef DBG
	#define DBG
    #define PRINT_VAR(X) {std::cout << (#X) << " : " << (X) << std::endl;}
    #endif // DBG

#ifndef M_PI
	#define M_PI 3.14159265358998
	#endif

const int windowWidth = 800;
const int windowHeight = 600;
const int gravity = 180;

bool inline isInWindow(int x, int y);

template<class IntType>
bool inline isInRange(IntType t,IntType a,IntType b);

template<class T>
T inline arctan(T y,T x);

template<class T>
T inline sq(T a);

inline float round(float number,float divisor);

inline double round(double number,double divisor);

sf::Vector2f RotatePoint(sf::Vector2f Point, sf::Vector2f Origin, double phi);

bool intersects(sf::CircleShape circle, sf::RectangleShape rect);

double cachedSqrt(int num);


sf::Color inline grad(double t , sf::Color a, sf::Color b)
{
    sf::Color res;
    res.r = LERP(t, a.r, b.r);
    res.g = LERP(t, a.g, b.g);
    res.b = LERP(t, a.b, b.b);
    res.a = LERP(t, a.a, b.a);
    return res;
}
#endif // UTILITIES_INCLUDED
