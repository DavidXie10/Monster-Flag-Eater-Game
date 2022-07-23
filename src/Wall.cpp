#include "Wall.h"

Wall::Wall(const int coordinateX, const int coordinateY)
    : InteractibleObject(coordinateX, coordinateY)
{
}

Wall::~Wall()
{
}

bool Wall::calculateNextCell(int& xP, int& yP, Board& board, const direction dir)
{
    (void)xP, (void)yP, (void)board, (void)dir;
    return false;
}


