
#include "BoxesController.h"

/**
  * @brief Instance the controller and run
  * @param argc number of arguments
  * @param argv vector with all the arguments
  * @return 0 if all runs correct
*/
int main(void)
{
    try {
        BoxesController game;
        return game.run();
    } catch (const std::runtime_error& error) {
        std::cerr << "\nMonster-Flag-Eater: " << error.what() << std::endl;
    }
    return 0;
}
