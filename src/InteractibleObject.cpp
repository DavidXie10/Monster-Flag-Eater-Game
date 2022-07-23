#include "InteractibleObject.h"

InteractibleObject::InteractibleObject(const int coordinateX, const int coordinateY)
    :coordinateX(coordinateX)
    , coordinateY(coordinateY)
{
}

InteractibleObject::~InteractibleObject()
{
}

bool InteractibleObject::calculateNextCell(int &xP, int &yP, Board &board, const direction dir)
{
    (void)dir;
    if(isValid(coordinateX, coordinateY, board) || endGame())
    {
        xP = this->coordinateX;
        yP = this->coordinateY;
        return true;
    }

    return false;
}

void InteractibleObject::setCoordinates(const int tempX, const int tempY)
{
    this->coordinateX = tempX;
    this->coordinateY = tempY;
}

bool InteractibleObject::isInRange(const int xInterac, const int yInterac, const Board &board)
{
    int rows = board.getRows();
    int columns = board.getColumns();
    return (xInterac >= 0 && xInterac < rows && yInterac >= 0 && yInterac < columns);
}

bool InteractibleObject::isValid(const int xInterac, const int yInterac, const Board &board)
{
    if (isInRange(xInterac, yInterac, board) )
        if ((board(xInterac, yInterac)->isPositionable()))
            return true;
    return false;
}

void InteractibleObject::changeCoordinates(InteractibleObject *first, InteractibleObject *second, Board &board)
{
    int xTmp = first->getX();
    int yTmp = first->getY();
    first->getX() = second->getX();
    first->getY() = second->getY();
    second->getX() = xTmp;
    second->getY() = yTmp;

    board.insert(second->getX(), second->getY(), second, false);
    board.insert(first->getX(), first->getY(), first, false);
}
