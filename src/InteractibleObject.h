#ifndef INTERACTIBLEOBJECT_H
#define INTERACTIBLEOBJECT_H

#include <iostream>

// static const char direction_ref[4] = {'N', 'E', 'S', 'O'};
static const int verticalDir[4] = {-1, 0, 1, 0};     // filas
static const int horizontalDir[4] = { 0, 1, 0,-1};   // columnas

/**
 * @typedef direction enumerator
 */
typedef enum{
    N, /**< North */
    E, /**< East */
    S, /**< South */
    O, /**< West */
    R, /**< Reset level option */
    U, /**< Unknown option */
}direction;

// We don't know why it doesn't work with just the #include "Board.h"
#include "Board.h"
class Board;

/**
 * @class InteractibleObject
 * @brief This is a base class for Interactible objects for our game, Monster flag eater. An example of usage:
 *
 * @code
 * InteractibleObject* object (1, 2);
 * if( object -> isPositionable() )
 *      std::cout << "Positionable" << std::endl;
 * @endcode
 */
class InteractibleObject
{
protected:
    int coordinateX;
    int coordinateY;

public:
    /**
     * @brief Explicit Constructor of class InteractibleObject, initialize it's atributes with the params coordinateX and Y of its position in the matrix
     * @param coordinateX X position in the matrix
     * @param coordinateY Y position in the matrix
     */
    explicit InteractibleObject(const int coordinateX, const int coordinateY);

    /**
     * @brief Destructor of class InteractibleObject
     */
    virtual ~InteractibleObject();

    /**
     * @brief Calculates the next cell in which the main Character is supossed to be
     * @param xP X coordinate reference in board of the main character
     * @param yP Y coordinate reference in board of the main character
     * @param board matrix of the game
     * @param dir Direction in which wants to go
     * @return true if character can be moved to another cell, false if remains in the same cell or if We make the move
     */
    virtual bool calculateNextCell(int& xP, int& yP, Board& board, const direction dir);

    /**
     * @brief Sets both the x and y value of interactibleObject when reseting
     * @param coordinate x to be set
     * @param coordinate y to be set
     */
    void setCoordinates(const int tempX, const int tempY);

    /**
     * @brief Checks if the cell is going to be in range of the matrix
     * @param coordinate X to check
     * @param coordinate y to check
     * @param board
     * @return true if its in, false if its out
     */
    static bool isInRange(const int xInterac, const int yInterac, const Board &board);

    /**
     * @brief Indicates if a (x,y) cell is in range of the board matrix
     * @param xInterac X coordinate in board to check
     * @param yInterac Y coordinate in board to check
     * @param board matrix of the game
     * @return true if it is valid, false otherwise
     */
    static bool isValid(const int xInterac, const int yInterac, const Board &board);

    /**
     * @brief Indicates if another interatible object can be put in this cell
     * @return true if an elment can be put in my cell for default
     */
    virtual inline bool isPositionable()const{return true;}

    /**
     * @brief endGame indicates if the game is finish when positioning in my cell
     * @return true if this cell ends the game, false otherwise
     */
    virtual inline bool endGame() const { return false; }

    /**
     * @brief change coordinates and their matrix position in board between two interactible objects
     * @param first an interactible object to be swap
     * @param second the other interactible object to be swap
     * @param board matrix of the game
     */
    static void changeCoordinates(InteractibleObject* first, InteractibleObject* second, Board &board);

protected:
    /**
     * @brief gets X coordinate
     * @return the x coordinate of the this object
     */
    inline int& getX(){return this->coordinateX;}

    /**
     * @brief gets Y coordinate
     * @return the y coordinate of the this object
     */
    inline int& getY(){return this->coordinateY;}

#if 1
/// In case the game is in commandline mode
public:
    /**
     * @brief the character to be printed according to its child
     * @param out the std::ostream to be used to print
     * @return the same std::ostream object
     */
    virtual std::ostream& print(std::ostream& out) = 0;
#endif

};

#endif // INTERACTIBLEOBJECT_H
