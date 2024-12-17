#include "Functions.h"

#include "Color.h"
#include "graphic.h"

_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;

bool backgroundMusicmode = true;
bool SFXmode = true; // false off, true on




int main() {
    
    //test
    BorderSquareLine(20, 40, 3, 5, 1);
    BorderSquare(10, 30, 6, 10, 1);
    
    //system("pause");

    system("color f0");
    setConsoleSize(120, 30);
    FixConsoleWindow();
    HideCursor();

    // openingscreen

    MenuHandler();

    return 0;
}
