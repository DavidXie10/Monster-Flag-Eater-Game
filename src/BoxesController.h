#ifndef BOXESCONTROLLER_H
#define BOXESCONTROLLER_H

#include "Board.h"
/**
 * @brief The BoxesController class. It is our Controller class in the MVC. It initiates the board and visual effects and acts as a link between them.
 */
class BoxesController
{
public:
    /**
     * @brief The constructor of the class BoxesController
     */
    BoxesController();

    /**
     * @brief The destructor of the class BoxesController
     */
    ~BoxesController();

    /**
     * @brief Executes the games. Is the controller class
     * @return 0 if all is good.
     */
    int run();

    /**
     * @brief return direction of input by user
     * @param direction
     * @return dir of input
     */
    direction getDirection(const char dir);

    /**
     * @brief insertElements type Interactible object in Board
     * @param The reference Board
     */
    void insertElements(Board& board);

    /**
     * @brief Print "Ganaste!" in case of winning
     * @return int
     */
    static int printWinningMessage();

};

#endif // BOXESCONTROLLER_H
