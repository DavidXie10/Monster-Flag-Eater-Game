#include "Board.h"

// Rows and columns level size
static const size_t rows = 5;
static const size_t columns = 6;

Board::Board()
    :matrixBoard(rows, std::vector<InteractibleObject*>(columns))
    , startingPosition(rows, std::vector<InteractibleObject*>(columns))
{
}

Board::~Board()
{
    for (unsigned long row = 0; row < startingPosition.size(); row++)
    {
        for (unsigned long col = 0; col < startingPosition[0].size(); col++)
        {
            delete matrixBoard[row][col];
        }
    }
}

void Board::insert(const int row, const int col, InteractibleObject* instanceObject, const bool isInitial)
{
    matrixBoard[row][col] = instanceObject;
    if (isInitial)
        startingPosition[row][col] = instanceObject;
}

void Board::reset()
{
    for (unsigned long row = 0; row < rows; row++)
    {
        for (unsigned long col = 0; col < columns; col++)
        {
            matrixBoard[row][col] = startingPosition[row][col];
            startingPosition[row][col]->setCoordinates(row,col);
        }
    }
}

#include "EmptyLot.h"
#include "Flag.h"
#include "IceFloor.h"
#include "MainCharacter.h"
#include "PushBox.h"
#include "Wall.h"

// This is the factory method
InteractibleObject* Board::createInteractibleObject(const char type, const int row, const int column)
{
    if ( type == 'M')
        return new MainCharacter(row, column);
    else if ( type == 'S')
        return new PushBox(row, column);
    else if ( type == '*')
        return new IceFloor(row, column);
    else if ( type == '.')
        return new EmptyLot(row, column);
    else if ( type == 'F')
        return new Flag(row, column);
    else if ( type == 'W')
        return new Wall(row, column);
    return nullptr;
}

void Board::print()
{
    std::cout << std::endl;
    for (unsigned int row = 0 ; row < rows ; row++)
    {
        for (unsigned int col = 0; col < columns ; col++)
        {
            matrixBoard[row][col]->print(std::cout);
            std::cout << std::setw(3) << " ";
        }
        if(row != rows - 1)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
