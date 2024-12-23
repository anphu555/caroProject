#include "Functions.h"

#include "Color.h"
#include "graphic.h"

_POINT _A[3][BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;

int musicSong = 0; // 0 menu, 1 ingame
bool backgroundMusicmode = true;
bool SFXmode = true; // false off, true on


int main() {
    setConsoleSize(120, 30);
    FixConsoleWindow();
    HideCursor();

    //intro ====================
    intro1(30, 11);
    introLoading();


    // ===================================================

    system("color b0");
    HideCursor();
    initWinsock();
    //cout << COLOR_RESET;

    MenuHandler();
    cleanupWinsock();
    return 0;
}
