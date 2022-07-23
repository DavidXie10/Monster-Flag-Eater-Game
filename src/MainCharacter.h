#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "InteractibleObject.h"

/**
 * @class MainCharacter
 * @brief This is a child class that inherits from Interactible objects for our game, Monster flag eater. This is the main character of the game, the one that will be moved across the board
 */
class MainCharacter : public InteractibleObject
{
public:
    /**
     * @brief Explicit Constructor of class MainCharacter, initialize it's atributes with the params coordinateX and Y of its position in the matrix
     * @param coordinateX X position in the matrix
     * @param coordinateY Y position in the matrix
     */
    explicit MainCharacter(const int coordinateX, const int coordinateY);

    /**
     * @brief Destructor of class MainCharacter
     */
    virtual ~MainCharacter()override;

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
        return out << 'M';
    }
#endif

};
#endif // MAINCHARACTER_H
