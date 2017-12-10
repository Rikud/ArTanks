#ifndef RESOURCEIDENTIFIERS_INCLUDED
#define RESOURCEIDENTIFIERS_INCLUDED
#include <SFML/Graphics.hpp>
enum TextureIdentifier
{
    TankTexture,
    ExplosionA,
    TurretTexture,
    TurretTarget,
    ArrowDownSpriteSheet,
    TitleBg
};
enum FontIdentifier
{
    Purisa,
    UbuntuCondensed
};

template <typename Resource, typename Identifier>
class ResourceManager;

typedef ResourceManager<sf::Texture,TextureIdentifier> TextureManager;
typedef ResourceManager<sf::Font,FontIdentifier> FontManager;


#endif // RESOURCEIDENTIFIERS_INCLUDED
