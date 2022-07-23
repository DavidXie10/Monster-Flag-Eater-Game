#include "BoxesController.h"
#include <iostream>
#include "InteractibleObject.h"

static const size_t rows = 5;
static const size_t columns = 6;

static const std::string startingMessage =
{
 "\n\t*   *  ***  *     *  **** ***** ***** **** \n"
   "\t** ** *   * **    * *       *   *     *   *\n"
   "\t* * * *   * * *   * *       *   *     *   *\n"
   "\t* * * *   * *  *  *  ***    *   ****  **** \n"
   "\t*   * *   * *   * *     *   *   *     * *  \n"
   "\t*   * *   * *    **     *   *   *     *  * \n"
   "\t*   *  ***  *     * ****    *   ***** *   *\n"

    "\n\t***** *      ***   *** \n"
      "\t*     *     *   * *    \n"
      "\t*     *     *   * *    \n"
      "\t****  *     ***** *    \n"
      "\t*     *     *   * *  **\n"
      "\t*     *     *   * *   *\n"
      "\t*     ***** *   *  *** \n"

    "\n\t*****  ***  ******* ***** ****  \n"
      "\t*     *   *    *    *     *   * \n"
      "\t*     *   *    *    *     *   * \n"
      "\t****  *****    *    ****  ****  \n"
      "\t*     *   *    *    *     * *   \n"
      "\t*     *   *    *    *     *  *  \n"
      "\t***** *   *    *    ***** *   * \n"
};

static const std::string winningMessage =
{
 "\n\t ***   ***  *     *  ***   **** ***** *****\n"
   "\t*     *   * **    * *   * *       *   *    \n"
   "\t*     *   * * *   * *   * *       *   *    \n"
   "\t*     ***** *  *  * *****  ***    *   **** \n"
   "\t*  ** *   * *   * * *   *     *   *   *    \n"
   "\t*   * *   * *    ** *   *     *   *   *    \n"
   "\t ***  *   * *     * *   * ****    *   *****\n"
};



BoxesController::BoxesController()
{
}

BoxesController::~BoxesController()
{
}

void BoxesController::insertElements(Board& board)
{
    for (unsigned int row = 0 ; row < rows ; row++)
    {
        for (unsigned int col = 0; col < columns ; col++)
        {
            char type;
            std::cin >> type;
            std::cin.ignore();
            InteractibleObject* instanceObject = Board::createInteractibleObject(type, row, col);
            board.insert(row, col, instanceObject, true);
        }
    }
}

int BoxesController::run()
{
    Board board;
    int xCharacter = 0, yCharacter = 0, xFlag = 0, yFlag = 0, xCharacterInitial = 0, yCharacterInitial = 0;
    std::cin >> xCharacter >> std::ws >> yCharacter >> std::ws >> xFlag >> std::ws >> yFlag >> std::ws;

    xCharacterInitial = xCharacter;
    yCharacterInitial = yCharacter;
    bool inGame = true;

    this->insertElements(board);

    std::cout << startingMessage << std::endl;

    std::cout << "\n\t    ¡Inicializado!\n";
    std::cout << "     ¡Que la fuerza te acompañe!\n";

    std::cout << "\nDirección (N, E, S, O) o R para reiniciar el nivel\n";

    while(inGame)
    {
        board.print();
        char dir;
        std::cout << "\nDirección: ";
        std::cin >> dir;

        direction direction = getDirection(dir);

        if(direction == R)
        {
            board.reset();
            xCharacter = xCharacterInitial;
            yCharacter = yCharacterInitial;
            continue;
        }
        else if (direction == U)
        {
            // throw std::runtime_error("unknown direction " + std::to_string(direction));
            std::cout << "unknown direction ";
            continue;
        }

        /// Determina cuál InteractObject hay en la posición que queremos ir acorde a la "direction"
        int nextX = xCharacter + verticalDir[direction];
        int nextY = yCharacter + horizontalDir[direction];


        if( InteractibleObject::isInRange(nextX, nextY, board) )
        {
            InteractibleObject* obj = board(nextX , nextY);

            int xCopy = xCharacter; // 1
            int yCopy = yCharacter; // 1

            /// Calcula la proximoa celda de MainCharacter
            if(obj->calculateNextCell(xCharacter, yCharacter, board, direction))
            {
                // xCharacter, yCharacter = 1, 2
                InteractibleObject::changeCoordinates(board(xCopy, yCopy), board(xCharacter, yCharacter), board);
            }
            if(obj->endGame())
            {
                if(xCharacter == xFlag && yCharacter == yFlag)
                    return this->printWinningMessage();
            }
        }
    }
    return 0;
}

direction BoxesController::getDirection(const char dir)
{
    //std::cout << "\nchar readed: " << dir << "\n";
    if(dir == 'N')
        return N;
    else if(dir == 'S')
        return S;
    else if(dir == 'E')
        return E;
    else if(dir == 'O')
        return O;
    else if(dir == 'R')
        return R;
    return U;       // X
}

int BoxesController::printWinningMessage()
{
    std::cout << winningMessage << std::endl;
    return 0;
}
