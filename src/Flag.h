#ifndef FLAG_H
#define FLAG_H

#include "InteractibleObject.h"

/**
 * @brief The Flag class. This is the objective of the main character. Once the main character reaches the Flag he wins the level.
 */
class Flag : public InteractibleObject
{
public:
    /**
     * @brief Construct of Flag. Initiliazes the flag were it is supposed to be.
     * @param receives coordinate x of initial position
     * @param receives coordinate y of initial position
     */
    explicit Flag(const int coordinateX, const int coordinateY);

    /**
     * @brief Destructor of Flag
     */
    virtual ~Flag() override;

    /**
     * @brief Defines if the character reaches the flag. In this case it would be true.
     * @return always true.
     */
    bool endGame() const override;

    /**
     * @brief Defines if the character can swap places with the flag
     * @return always false.
     */
    bool isPositionable() const override;

#if 1
    /// METHOD NEW
    /**
     * @brief the cahracter to be printed
     * @param out the std::ostream to be used to print
     * @return the same std::ostream object
     */
    inline virtual std::ostream& print(std::ostream& out) override{
        return out << 'F';
    }
#endif
};


#endif // FLAG_H
