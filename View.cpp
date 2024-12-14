#include "Functions.h"
#include "Color.h"

#include "graphic.h"


extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;


void GotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void FixConsoleWindow()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) & ~(WS_VSCROLL); // tat nut maximize, resize, 2 thanh cuon
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void HideCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void AppearCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(out, &cursorInfo);
}



void DrawBoard() // pSize = BOARD_SIZE
{
    AppearCursor();

    cout << COLOR_GREEN << COLOR_BOLD; // tao mau cho toan bang

    // ve canh tren, khong ve 4 goc
    GotoXY(LEFT + 1, TOP);
    for (int i = 1; i < 4 * BOARD_SIZE; i++) // ko lay o cuoi o goc nen <
    {
        if (i % 4 == 0)
            cout << char(209);
        else
            cout << char(205);
    }
    // ve canh duoi, khong ve goc
    GotoXY(LEFT + 1, BOTTOM);
    for (int i = 1; i < 4 * BOARD_SIZE; i++) // ko lay o cuoi o goc nen <
    {
        if (i % 4 == 0)
            cout << char(207);
        else
            cout << char(205);
    }
    // tao các dòng cho bàn co
    char Line0[4*BOARD_SIZE + 1 + 1];   // dòng có ô trong, +1 cho vien phai, +1 de them '\0'
    char Line1[4 * BOARD_SIZE + 1 + 1]; // dòng vien

    // ngay mep
    Line0[0] = Line0[4 * BOARD_SIZE] = 186;
    Line0[4 * BOARD_SIZE + 1] = '\0';
    
    Line1[0] = 199;
    Line1[4 * BOARD_SIZE] = 182;
    Line1[4 * BOARD_SIZE + 1] = '\0';

    // khoi tao tung dòng
    for (int i = 1; i < 4 * BOARD_SIZE; i++)
    {
        if (i % 4 == 0)
        {
            Line0[i] = 179; // vi tri vien o
            Line1[i] = 197;
        }
        else
        {
            Line0[i] = ' ';
            Line1[i] = 196;
        }
    }
    // ve các dòng
    for (int i = 1; i < 2 * BOARD_SIZE; i++)
    {
        GotoXY(LEFT, TOP + i);
        if (i % 2 != 0)
            cout << Line0;
        else
            cout << Line1;
    }
    // ve cac goc
    GotoXY(LEFT, TOP);      cout << char(201);
    GotoXY(LEFT, BOTTOM);   cout << char(200);
    GotoXY(RIGHT, TOP);     cout << char(187);
    GotoXY(RIGHT, BOTTOM);  cout << char(188);

    cout << COLOR_RESET;
}

int ProcessFinish(int pWhoWin)
{
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
    if (pWhoWin == 2) // chưa có ai thắng hoặc hòa
    {
        _TURN = !_TURN;
    }
    else
    {
        // 50,15 là tọa độ kiểm thử
        WinEffect(50, 15, pWhoWin);
    }
    
    //switch (pWhoWin)
    //{
    //case -1:
    //    // o win
    //    WinEffect(50, 15, pWhoWin);
    //    cout << "Nguoi choi O da thang va nguoi choi X da thua" << endl;
    //    break;
    //case 1:
    //    // x win
    //    cout << "Nguoi choi X da thang va nguoi choi O da thua" << endl;
    //    break;
    //case 0:
    //    // draw
    //    cout << "Hai ben da hoa!" << endl;
    //    break;
    //case 2:
    //    _TURN = !_TURN;
    //}
    GotoXY(_X, _Y);
    return pWhoWin;
}

int AskContinue()
{
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);

    cout << "Nhan y/n de choi lai hoac thoat: ";
    return toupper(getch());
}