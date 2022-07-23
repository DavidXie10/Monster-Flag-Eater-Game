#include "Flag.h"

Flag::Flag(const int coordinateX, const int coordinateY)
    :InteractibleObject(coordinateX, coordinateY)
{
}

Flag::~Flag()
{

}

bool Flag::endGame() const
{
    return true;
}

bool Flag::isPositionable() const
{
    return false;
}
