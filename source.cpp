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
    //system("pause");
    BorderSquare(10, 30, 3, 8, 2);
    //GotoXY(70, 20);
    //system("pause");

    system("color f0");
    setConsoleSize(120, 30);
    FixConsoleWindow();
    HideCursor();

    // openingscreen

    MenuHandler();

    return 0;
}
