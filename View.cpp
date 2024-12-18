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

void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // handle tro vo cai console

    // Get the console screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

    // Set the size of the screen buffer
    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
    COORD bufferSize = { width, height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Set the console window size
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
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
    // ve cac goc ria ban co
    GotoXY(LEFT, TOP);      cout << char(203); 
    GotoXY(LEFT, BOTTOM);   cout << char(202);
    GotoXY(RIGHT, TOP);     cout << char(203);
    GotoXY(RIGHT, BOTTOM);  cout << char(202);

    // vẽ rộng ra 2 bên bàn cờ
    GotoXY(LEFT - 33 - 1, TOP);      cout << char(201);  // goc ria ngoai
    GotoXY(LEFT - 33 - 1, BOTTOM);   cout << char(200);
    GotoXY(RIGHT + 33 + 1, TOP);     cout << char(187);
    GotoXY(RIGHT + 33 + 1, BOTTOM);  cout << char(188);

    for (int i = 1; i <= 33; i++) // ve cac duong noi tren
    {
        GotoXY(LEFT - i, TOP);       cout << char(205);
        GotoXY(LEFT - i, BOTTOM);    cout << char(205);
        GotoXY(RIGHT + i, TOP);      cout << char(205);
        GotoXY(RIGHT + i, BOTTOM);   cout << char(205);
    }
    for (int i = 1; i < (BOTTOM - TOP); i++)
    {
        GotoXY(LEFT - 33 - 1, TOP + i);  cout << char(186);
        GotoXY(RIGHT + 33 + 1, TOP + i); cout << char(186);
    }
    
    cout << COLOR_RESET;

    // ve them x o o 2 ben
    if (_TURN)
    {
        cout << COLOR_RED;
        XLogo(15, 4); 
        cout << COLOR_RESET;

        cout << COLOR_WHITE COLOR_DARK;
        OLogo(98, 4);
        cout << COLOR_RESET;
    }
    else
    {
        cout << COLOR_WHITE COLOR_DARK;
        XLogo(15, 4);
        cout << COLOR_RESET;

        cout << COLOR_BLUE;
        OLogo(98, 4);
        cout << COLOR_RESET;
    }

    BorderSquareLine(16, 20, 14, 16, 0);
    GotoXY(18, 15); cout << "W";

    BorderSquareLine(16, 20, 16, 18, 0);
    GotoXY(18, 17); cout << "S";

    BorderSquareLine(12, 16, 16, 18, 0);
    GotoXY(14, 17); cout << "A";

    BorderSquareLine(20, 24, 16, 18, 0);
    GotoXY(22, 17); cout << "D";

    GotoXY(16, 16); cout << char(206);
    GotoXY(20, 16); cout << char(206);

    GotoXY(16, 18); cout << char(202);
    GotoXY(20, 18); cout << char(202);

    BorderSquareLine(14, 22, 19, 21, 0);
    GotoXY(16, 20); cout << "ENTER";



    BorderSquareLine(99, 103, 14, 16, 0);
    BorderSquareLine(99, 103, 16, 18, 0);
    BorderSquareLine(95, 99, 16, 18, 0);
    BorderSquareLine(103, 107, 16, 18, 0);

    GotoXY(99, 16); cout << char(206);
    GotoXY(103, 16); cout << char(206);

    GotoXY(99, 18); cout << char(202);
    GotoXY(103, 18); cout << char(202);

    BorderSquareLine(97, 105, 19, 21, 0);
    GotoXY(99, 20); cout << "ENTER";

    int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, luu vô để hồi đổi lại
    GotoXY(101, 15); wcout << L"⮝";
    GotoXY(101, 17); wcout << L"⮟";
    GotoXY(97, 17); wcout << L"⮜";
    GotoXY(105, 17); wcout << L"⮞";
    //wcout << L"⮜ ⮞ ⮝ ⮟";
    //⮜ ⮞ ⮝ ⮟
  
    int CurrentMode = _setmode(_fileno(stdout), OldMode);

}

int ProcessFinish(int pWhoWin)
{
    GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
    if (pWhoWin == 2) // chưa có ai thắng hoặc hòa
    {
        _TURN = !_TURN;
    }
    else if (pWhoWin == 1)
    {
        // 50,15 là tọa độ kiểm thử
        WinEffect(2.5, 15, pWhoWin);
    }
    else if (pWhoWin == -1)
    {
        // 50,15 là tọa độ kiểm thử
        WinEffect(84, 15, pWhoWin);
    }

    else if (pWhoWin == 0) {
            WinEffect(50, 5, pWhoWin);
    }

    // ve lai x o voi mau theo luot
    if (_TURN)  // luot x
    {
        cout << COLOR_RED;
        XLogo(15, 4);
        cout << COLOR_RESET;

        cout << COLOR_WHITE COLOR_DARK;
        OLogo(98, 4);
        cout << COLOR_RESET;
    }
    else
    {   
        cout << COLOR_WHITE COLOR_DARK;
        XLogo(15, 4);
        cout << COLOR_RESET;

        cout << COLOR_BLUE;
        OLogo(98, 4);
        cout << COLOR_RESET;
	}

    GotoXY(_X, _Y);
    return pWhoWin;
}

int AskContinue()
{
    //GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);
    //system("color f0");

    //GotoXY(80, 50);
    HideCursor();
    const int NUM_REPLAY_ITEMS = 2;
    const char* replayItems[NUM_REPLAY_ITEMS] = {
        "   PLAY AGAIN   ",
        "   Exit   "
    };

    int selectedItem = 3;

    while (1) {
        if (selectedItem == 0) {

            replayItems[selectedItem] = ">> PLAY AGAIN <<";

            replayItems[(selectedItem + 1 + NUM_REPLAY_ITEMS) % NUM_REPLAY_ITEMS] = "   Exit   ";
        }
        else if (selectedItem == 1) {
            replayItems[selectedItem] = ">> Exit <<";

            replayItems[(selectedItem + 1 + NUM_REPLAY_ITEMS) % NUM_REPLAY_ITEMS] = "   PLAY AGAIN   ";
        }

        int toadoX1 = LEFT + 7; // tọa đọ test vị trsi settings
        for (int i = 0; i < NUM_REPLAY_ITEMS; i++) {
            GotoXY(toadoX1 + i * 25, 15);

            if (i == selectedItem) {
                cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
                cout << replayItems[i];
                cout << COLOR_RESET;
            }
            else {
                cout << replayItems[i];
            }
        }

        // lựa chọn các item
        char key = _getch();

        switch (key) {
        case 75:    case 'A':   case 'a':
            selectedItem = (selectedItem - 1 + NUM_REPLAY_ITEMS) % NUM_REPLAY_ITEMS;
            break;

        case 77:  case 'D':   case 'd':
            selectedItem = (selectedItem + 1 + NUM_REPLAY_ITEMS) % NUM_REPLAY_ITEMS;
            break;

        case ENTER_KEY:
            switch (selectedItem)
            {
            case 0:
                return 'Y';
            case 1:
                return 'N';
            }
            break;
        }
    }

    //cout << 
    //cout << "Nhan y/n de choi lai hoac thoat: ";
    return toupper(getch());
}

    

    

    