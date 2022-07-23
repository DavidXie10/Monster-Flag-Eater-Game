#ifndef WALL_H
#define WALL_H

#include "InteractibleObject.h"

/**
 * @class Wall
 * @brief This is a child class that inherits from Interactible objects for our game, Monster flag eater. This is just a simple cell in which no one can be put and that can not be pushed or pulled, basically it can not be moved.
 */
class Wall : public InteractibleObject
{
public:
    /**
     * @brief Explicit Constructor of class Wall, initialize it's atributes with the params coordinateX and Y of its position in the matrix
     * @param coordinateX X position in the matrix
     * @param coordinateY Y position in the matrix
     */
    explicit Wall(const int coordinateX, const int coordinateY);

    /**
     * @brief Destructor of class Wall
     */
    virtual ~Wall()override;

    /**
     * @brief The coordinates of the main character remains the same ones as they enter because no one can be in this spot
     * @param xP X coordinate reference in board of the main character
     * @param yP Y coordinate reference in board of the main character
     * @param board matrix of the game
     * @param dir Direction in which wants to go
     * @return false because remains in the same cell
     */
    virtual bool calculateNextCell(int& xP, int& yP, Board& board, const direction dir) override;

    /**
     * @brief Indicates if another interatible object can be put in this cell
     * @return false because no element can be put on wall
     */
    virtual inline bool isPositionable()const override{return false;}

#if 1
/// In case the game is in commandline mode
public:
    /**
     * @brief the character to be printed
     * @param out the std::ostream to be used to print
     * @return the same std::ostream object
     */
    inline virtual std::ostream& print(std::ostream& out) override{
        return out << 'W';
    }
#endif

};

#endif // WALL_H
