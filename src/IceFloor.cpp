
#include "IceFloor.h"

IceFloor::IceFloor(const int coordinateX, const int coordinateY)
    :InteractibleObject(coordinateX, coordinateY)
{
}

IceFloor::~IceFloor()
{
}

bool IceFloor::calculateNextCell(int &xP, int &yP, Board &board, const direction dir)
{
    // I know I am IceFloor, so obviously the Main Character is going to my floor!
    // Switch interactive objects between the main character and the ice floor
    int tmpX = this->coordinateX;
    int tmpY = this->coordinateY;
    InteractibleObject::changeCoordinates(board(xP, yP), this, board);

    // Then see if there are more ice floors in the same direction provided
    xP = tmpX;
    yP = tmpY;
    int nextX = xP + verticalDir[dir];
    int nextY = yP + horizontalDir[dir];

    bool finish = false;
    if(!finish && isValid(nextX, nextY, board))
    {
#if 1
        board.print();
        std::cout << std::endl;
#endif
        finish = !board(nextX, nextY)->calculateNextCell(xP, yP, board, dir);
    }

    return false;
}
