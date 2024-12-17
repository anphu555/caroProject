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
    setConsoleSize(120, 30);
    cout << BACKGROUND_WHITE;
    BorderSquareFILL(0, 119, 0, 8);
    cout << BACKGROUND_CYAN;
    BorderSquareFILL(0, 119, 9, 30);

    GotoXY(4, 5); cout << "teset";
    GotoXY(4, 17); cout << "teset";
    system("pause");

    // test============================


    intro1(30, 11);
    introLoading();

    //system("color f0");
    cout << COLOR_RESET;
   

    setConsoleSize(120, 30);
    FixConsoleWindow();
    HideCursor();

    //Group10Logo(1, 2);
    // openingscreen

    MenuHandler();

    return 0;
}
