#include "Functions.h"

#include "Color.h"
#include "graphic.h"

_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;

bool backgroundMusicmode = true;
bool SFXmode = true; // false off, true on

//HWND WINAPI GetConsoleWindowNT(void)
//{
//    //declare function pointer type
//    typedef HWND WINAPI(*GetConsoleWindowT)(void);
//    //declare one such function pointer
//    GetConsoleWindowT GetConsoleWindow;
//    //get a handle on kernel32.dll
//    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
//    //assign procedure address to function pointer
//    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
//        , TEXT("GetConsoleWindow"));
//    //check if the function pointer is valid
//    //since the function is undocumented
//    if (GetConsoleWindow == NULL) {
//        return NULL;
//    }
//    //call the undocumented function
//    return GetConsoleWindow();
//}



int main() {
    // chua tao duoc kich thuoc cua so choi game (bao nhieu pixel)

   /* HDC screen = GetDC(NULL);
    while (1)
    {
        Rectangle(screen, 50, 50, 5000, 5000);
        Sleep(1000);
    }*/
 /*   SMALL_RECT ConsoleSize;
    HWND consoleWindow = GetConsoleWindow();
    SetConsoleWindowInfo(consoleWindow, 1, &ConsoleSize);*/

 /*   HWND hWnd = GetConsoleWindowNT();
    MoveWindow(hWnd, 1230, 600, 300, 200, TRUE);*/

    system("color f0");
    FixConsoleWindow();
    HideCursor();
    MenuHandler();
    WinEffect(10, 5, -1);
    PlaySound(0, 0, 0);
    winSound();
    return 0;
}
