#ifndef ICEFLOOR_H
#define ICEFLOOR_H

#include "InteractibleObject.h"
#include "Board.h"
class Board;

/**
 * @class IceFloor
 * @brief This is a child class that inherits from Interactible objects for our game, Monster flag eater. If the main character is in a cell of this kind and tries to move, then it continues moving until it hits a wall, a box, or an empty space.
 */
class IceFloor : public InteractibleObject
{
public:
    /**
     * @brief Explicit Constructor of class IceFloor, initialize it's atributes with the params coordinateX and Y of its position in the matrix
     * @param coordinateX X position in the matrix
     * @param coordinateY Y position in the matrix
     */
    explicit IceFloor(const int coordinateX, const int coordinateY);

    /**
     * @brief Destructor of class IceFloor
     */
    virtual ~IceFloor()override;

    /**
     * @brief Moves the main character though all the ice floor spotted at the same direction as the one provided until it reaches a wall, a box, or an empty space.
     * @param xP X coordinate reference in board of the main character
     * @param yP Y coordinate reference in board of the main character
     * @param board matrix of the game
     * @param dir Direction in which wants to go
     * @return always false because here is where all the pieces are move
     */
    virtual bool calculateNextCell(int& xP, int& yP, Board& board, const direction dir) override;

    /**
     * @brief Checks wether this object can swap places.
     * @return true if it can swap places
     */
    virtual inline bool isPositionable()const override{return true;}

    /**
     * @brief the character to be printed
     * @param out the std::ostream to be used to print
     * @return the same std::ostream object
     */
    inline virtual std::ostream& print(std::ostream& out) override{
        return out << '*';
    }

};
#endif // ICEFLOOR_H
