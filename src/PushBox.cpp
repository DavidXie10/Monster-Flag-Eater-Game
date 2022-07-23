#include "PushBox.h"

PushBox::PushBox(const int coordinateX, const int coordinateY)
    :InteractibleObject(coordinateX, coordinateY)
{
}

PushBox::~PushBox()
{
}

bool PushBox::calculateNextCell(int &xP, int &yP, Board &board, const direction dir)
{
    int nextX = this->coordinateX + verticalDir[dir];
    int nextY = this->coordinateY + horizontalDir[dir];

    int oldX = xP;
    int oldY = yP;

    if(isValid(nextX, nextY, board))
    {
       xP = this->coordinateX;
       yP = this->coordinateY;
       changeCoordinates(this, board(nextX, nextY), board);
    }
    return ! (oldX == xP && oldY == yP);
}
