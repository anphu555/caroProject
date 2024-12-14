#include "Functions.h"
#include "Color.h"

extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;


// tam thoi de nen TIM (background_magneta) truoc moi cai "cout" =============


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
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void DrawBoard() // pSize = BOARD_SIZE
{
    // tam de nen la tim (background_magneta
    // cai bang se co mau xanh
    cout << BACKGROUND_MAGNETA << COLOR_GREEN << COLOR_BOLD; // tao mau cho toan bang

    int i, j;
    GotoXY(LEFT + 1, TOP);   // TOP
    for (i = 0; i < (2 * BOARD_SIZE); i++)
        if (i % 2)
            printf("%c", 194);
        else
            printf("%c%c%c", 196, 196, 196);
    GotoXY(LEFT + 1, BOTTOM); // BOTTOM
    for (i = 0; i < 2 * BOARD_SIZE; i++)
        if (i % 2)
            printf("%c", 193);
        else
            printf("%c%c%c", 196, 196, 196);
    for (i = 0; i < 2 * BOARD_SIZE; i++)
    {
        GotoXY(LEFT, TOP + i);
        if (i % 2)
            printf("%c", 179);
        else
            printf("%c", 195);
        GotoXY(RIGHT, TOP + i);
        if (i % 2)
            printf("%c", 179);
        else
            printf("%c", 180);
    }
    char S0[200], S1[200];
    for (int j = 0; j < 4 * BOARD_SIZE - 1; j++)
        if (j % 4 == 0)
            S0[j] = 179;
        else
            S0[j] = ' ';
    for (int j = 0; j < 4 * BOARD_SIZE - 1; j++)
        if ((j + 1) % 4 == 0)
            S1[j] = 197;
        else
            S1[j] = 196;
    S1[4 * BOARD_SIZE - 1] = '\0';
    S0[4 * BOARD_SIZE - 1] = '\0';
    i = 1;
    while (i < 2 * BOARD_SIZE - 1)
    {
        GotoXY(LEFT, TOP + i++);
        printf("%s", S0);
        GotoXY(LEFT + 1, TOP + i++);
        printf("%s", S1);
    }
    GotoXY(LEFT, TOP + i);
    printf("%s", S0);
    GotoXY(LEFT, TOP);
    printf("%c", 218);
    GotoXY(RIGHT, TOP);
    printf("%c", 191);
    GotoXY(LEFT, BOTTOM);
    printf("%c", 192);
    GotoXY(RIGHT, BOTTOM);
    printf("%c", 217);

    cout << COLOR_RESET;
}

int ProcessFinish(int pWhoWin)
{
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
    switch (pWhoWin)
    {
    case -1:
        cout << BACKGROUND_MAGNETA;
        cout << "Nguoi choi O da thang va nguoi choi X da thua" << COLOR_RESET << endl;
        break;
    case 1:
        cout << BACKGROUND_MAGNETA;
        cout << "Nguoi choi X da thang va nguoi choi O da thua" << COLOR_RESET << endl;
        break;
    case 0:
        cout << BACKGROUND_MAGNETA;
        cout << "Hai ben da hoa!" << COLOR_RESET << endl;
        break;
    case 2:
        _TURN = !_TURN;
    }
    GotoXY(_X, _Y);
    return pWhoWin;
}

int AskContinue()
{
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);
    cout << BACKGROUND_MAGNETA;
    cout << "Nhan y/n de tiep tuc hoac dung: ";
    return toupper(getch());
}

// void display(char board[][BOARD_SIZE]) {
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         for (int j = 0; j < BOARD_SIZE; j++) {
//             board[i][j] = '.';
//         }
//     }
//     cout << "  ";
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         cout << i << " ";
//     }
//     cout << endl;

//     for (int i = 0; i < BOARD_SIZE; i++) {
//         cout << i << " ";
//         for (int j = 0; j < BOARD_SIZE; j++) {
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
// }