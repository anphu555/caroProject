#include "Functions.h"

#include "Color.h"
#include "graphic.h"

_POINT _A[3][BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;

bool backgroundMusicmode = true;
bool SFXmode = true; // false off, true on




int main() {
    setConsoleSize(120, 30);
    FixConsoleWindow();
    HideCursor();

    //intro ====================
    intro1(30, 11);
    introLoading();


    //backgroundGraphic();

    //GotoXY(1, 10);
    //system("pause");

    // test===============================================
    //setConsoleSize(120, 30);
    //cout << BACKGROUND_WHITE;
    //BorderSquareFILL(0, 119, 0, 8);
    //cout << BACKGROUND_CYAN;
    //BorderSquareFILL(0, 119, 9, 30);

    //GotoXY(4, 5); cout << "teset";
    //GotoXY(4, 17); cout << "teset";
    //system("pause");
    
    //GotoXY(50, 28);
    //system("pause");

    // ===================================================

    system("color b0");

    
    //cout << COLOR_RESET;

    MenuHandler();

    return 0;
}
