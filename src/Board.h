#ifndef BOARD_H
#define BOARD_H

#include <iomanip>
#include <iostream>
#include <vector>

#include "InteractibleObject.h"
#include "Common.h"
class InteractibleObject;

/**
 * @class Board
 * @brief This is the class that has the matrix that is the board. Each cell consists in a pointer to an interactibleObject. Contains the x and y coordinates of both the main character and the flag.
 */
class Board
{
    DISABLE_COPY(Board);

private:
    std::vector<std::vector<InteractibleObject*>> matrixBoard;
    std::vector<std::vector<InteractibleObject*>> startingPosition;
    int characterX;
    int characterY;
    int flagX;
    int flagY;

public:
    /**
     * @brief Constructor of class Board. It creates two matrixes of InteractibleObject*, one is the matrixBoard and the other the startingPosition
     */
    Board();

    /**
      * @brief Destructor of class Board. Deletes both matrixes
      */
    ~Board();

    /**
     * @brief Inserts the the InteractibleObject in the board
     * @param Row in the board which the interactive object its going to be
     * @param Cow in the board which the interactive object its going to be
     * @param Pointer to InteractiveObject which its going to be in the board.
     * @param isInitial Determines if its the first time the element is going to be inserted.
     */
    void insert(const int row, const int col, InteractibleObject* instanceObject, const bool isInitial);

    /**
     * @brief Its the factory method in which analyzes which type of InteractibleObject is.
     * @param receives char that represent the interactive object in the position. M = MainCharacter, S = PushBox, L = PullBox, I = IceFloor, E = EmptyLot, F = Flag.
     * @return pointer to the interactive object.
     */
    static InteractibleObject* createInteractibleObject(const char type, const int row, const int column);

    /**
     * @brief Sets the board in its initial state
     */
    void reset();

    /**
     * @brief Return
     * @param row
     * @param column
     * @return const InteractiveObject pointer at row, column position
     */
    inline InteractibleObject* operator()(const int row, const int column){return this->matrixBoard[row][column];}

    /**
     * @brief operator ()
     * @param row
     * @param column
     * @return InteractiveObject pointer at row, column position
     */
    inline InteractibleObject* operator()(const int row, const int column) const {return this->matrixBoard[row][column];}

    /**
     * @brief gets the amount of rows in matrixBoard
     * @return int of rows in the matrixBoard
     */
    inline int getRows()const{return this->matrixBoard.size();}

    /**
     * @brief gets the amount of cols in matrixBoard
     * @return int of cols in the matrixBoard
     */
    inline int getColumns()const{return this->matrixBoard[0].size();}

public:
    /**
     * @brief prints matrixBoard
     */
    void print();

};

#endif // BOARD_H
