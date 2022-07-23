#ifndef EMPTYLOT_H
#define EMPTYLOT_H

#include "InteractibleObject.h"

/**
 * @brief The EmptyLot class. This are the tiles in which there is nothing in it, so the main character can easily walk into them.
 */
class EmptyLot : public InteractibleObject
{
public:
    /**
     * @brief Constructor of EmptyLot. Initilizes the object with the coordinates were it first stands.
     * @param coordinate x were it first stands on the board
     * @param coordinate y were it first stands on the board.
     */
    explicit EmptyLot(const int coordinateX, const int coordinateY);

    /**
     * @brief Destructor of EmptyLot
     */
    virtual ~EmptyLot()override;

    /**
     * @brief decides wether this object can swap places with any other character.
     * @return always true
     */
    virtual inline bool isPositionable() const override{return true;}

#if 1
    /// METHOD NEW
    /**
     * @brief the cahracter to be printed
     * @param out the std::ostream to be used to print
     * @return the same std::ostream object
     */
    inline virtual std::ostream& print(std::ostream& out) override{
        return out << '.';
    }
#endif
};


#endif // EMPTYLOT_H
