#ifndef PUSHBOX_H
#define PUSHBOX_H

#include "InteractibleObject.h"

/**
 * @class PushBox
 * @brief This is a child class that inherits from Interactible objects for our game, Monster flag eater. It has a box in it so that it can be pushed according to the direction provided.
 */
class PushBox : public InteractibleObject
{
public:
    /**
     * @brief Explicit Constructor of class PushBox, initialize it's atributes with the params coordinateX and Y of its position in the matrix
     * @param coordinateX X position in the matrix
     * @param coordinateY Y position in the matrix
     */
    explicit PushBox(const int coordinateX, const int coordinateY);

    /**
     * @brief Destructor of class PushBox
     */
    virtual ~PushBox()override;

    /**
     * @brief Calculates the next cell in which the main Character is supossed to be and also moves the box in the direction provided if it is valid and positionable
     * @param xP X coordinate reference in board of the main character
     * @param yP Y coordinate reference in board of the main character
     * @param board matrix of the game
     * @param dir Direction in which wants to go
     * @return true if character can be moved to another cell, false if remains in the same cell or if We make the move
     */
    virtual bool calculateNextCell(int& xP, int& yP, Board& board, const direction dir) override;

    /**
     * @brief Indicates if another interatible object can be put in this cell
     * @return false because no element can be put on the main character
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
        return out << 'S';
    }
#endif
};

#endif // PUSHBOX_H
