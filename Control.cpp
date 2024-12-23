#include "Functions.h"
#include "graphic.h"
#include "Color.h"

extern _POINT _A[3][BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;

extern bool backgroundMusicmode;
extern bool SFXmode;

int moveXCount = 0;
int moveOCount = 0;


void StartGame() {
    moveXCount = 0;
    moveOCount = 0;

    system("cls");
    ResetData();
    DrawBoard();
   
   
    // Khi khoi dong game, con tro o giua man hinh
    _X += (BOARD_SIZE/2) * (4);     // vi 1 o la 4x2
    _Y += (BOARD_SIZE / 2) * (2);
    GotoXY(_X, _Y);
}

void ExitGame() {
    system("cls");
    //GarbageCollect();
}

void MoveRight() {
    if (_X < _A[0][BOARD_SIZE - 1][BOARD_SIZE - 1].x)
    {
        _X += 4;
        GotoXY(_X, _Y);
    }
}

void MoveLeft() {
    if (_X > _A[0][0][0].x)
    {
        _X -= 4;
        GotoXY(_X, _Y);
    }
}

void MoveDown() {
    if (_Y < _A[0][BOARD_SIZE - 1][BOARD_SIZE - 1].y)
    {
        _Y += 2;
        GotoXY(_X, _Y);
    }
}

void MoveUp() {
    if (_Y > _A[0][0][0].y)
    {
        _Y -= 2;
        GotoXY(_X, _Y);
    }
}

void GameMove()
{
   bool validEnter = true;
   while(1) {
        _COMMAND = toupper(getch());
        // xet tung nut bam
        switch(_COMMAND) {
            case 27: { // phim esc la 27
                InGameMenu();
                break; // Changed from ExitGame() to open menu
            }
            // WASD cho X, mui ten cho O
            // nut danh luot X (_TURN true)
            case 'A': { 
                if(_TURN) MoveLeft();
                break;
            }
            case 'W': { 
                if(_TURN) MoveUp();
                break;
            }
            case 'S': { 
                if(_TURN) MoveDown();
                break;
            }
            case 'D': {
                if(_TURN) MoveRight();
                break;
            }
            // _TURN false (luot O)
            case 75: {          // left arrow: 75
                if(!_TURN) MoveLeft();
                break;
            }
            case 72: {          // up arrow: 72
                if(!_TURN) MoveUp();
                break;
            }
            case 80: {          // down arrow: 80
                if(!_TURN) MoveDown();
                break;
            }
            case 77: {          // right arrow: 77
                if(!_TURN) MoveRight();
                break;
            }
            // press Enter
            case 13: {
                switch (CheckBoard(_X, _Y, 0)) 
                {
                    
                case -1:
                    cout << BACKGROUND_WHITE;
                    cout << COLOR_RED << COLOR_BOLD<< "X" << COLOR_RESET;
                    enterXSound();
                    moveXCount++;
                    GotoXY(10, 12); 
                    cout << COLOR_RED "Moves player X: " << moveXCount << COLOR_RESET;
                    break;
                
                case 1:
                    cout << BACKGROUND_WHITE;
                    cout << COLOR_BLUE << COLOR_BOLD<< "O" << COLOR_RESET;
                    enterOSound();
                    moveOCount++;
                    GotoXY(93, 12); 
                    cout << COLOR_BLUE "Moves player O: " << moveOCount << COLOR_RESET;
                    break;
                
                case 0:
                    validEnter = false; //danh vao o dah roi
                }
                // check win/lose/draw/continue
                if (validEnter == true)
                {
                    switch (ProcessFinish(TestBoard(0)))
                    {
                    case -1: case 1: case 0:
                        if (AskContinue() != 'Y')
                        {
                            /*ExitGame();*/
                            // gọi lại như lúc vào game
                            MenuHandler();
                            return;
                        }
                        else
                            StartGame();
                    }
                }
                validEnter = true; // unlock
            }
        }
    }
}


void moveWASDAI()
{

    bool validEnter = true;

    while (1) {
        _COMMAND = toupper(getch());
        // xet tung nut bam
        switch (_COMMAND) {
        case 27: { // phim esc la 27
            InGameMenu();
            break; // Changed from ExitGame() to open menu
        }
               // WASD cho X, mui ten cho O
               // nut danh luot X (_TURN true)
        case 'A': {
            MoveLeft();
            break;
        }
        case 'W': {
            MoveUp();
            break;
        }
        case 'S': {
            MoveDown();
            break;
        }
        case 'D': {
            MoveRight();
            break;
        }
        case 13: {
            switch (CheckBoard(_X, _Y, 0))
            {
            case -1:
                cout << BACKGROUND_WHITE;
                cout << COLOR_RED << COLOR_BOLD << "X" << COLOR_RESET;
                enterXSound();
                moveXCount++;
                GotoXY(10, 12);
                cout << COLOR_RED "Moves player X: " << moveXCount << COLOR_RESET;


                // check win/lose/draw/continue
                switch (ProcessFinish(TestBoard(0)))
                {
                case -1: case 1: case 0:
                    if (AskContinue() != 'Y')
                    {
                        ExitGame();
                        return;
                    }
                    else
                    {
                        //return;
                        StartGame();
                        _TURN = true;
                        //moveWASDAI();
                    }
                    break;
                case 2:
                    // continue
                    
                    // AI Play
                    AIPlay();
                    moveOCount++;
                    GotoXY(93, 12); // Hiển thị dưới bàn cờ
                    cout << COLOR_BLUE "   Moves Bot: " << moveOCount << COLOR_RESET;
                    // check win/lose/draw/continue
                    switch (ProcessFinish(TestBoard(0)))
                    {
                    case -1: case 1: case 0:
                        if (AskContinue() != 'Y')
                        {
                            ExitGame();
                            return;
                        }
                        else
                        {
                            StartGame();
                            //moveWASDAI();
                        }
                        break;
                    case 2:
                        // continue
                        break;
                    }
                    break;
                }
                
                _TURN = true; //ai tu doi turn roi
                break;

            case 0:
                validEnter = false; //danh vao o dah roi
            }
            validEnter = true; // unlock
        }
        }
    }
}

bool moveWASDLAN() {
    bool validEnter = true;
    bool moveMade = false;

    while (1) {  // Keep the loop for continuous movement
        _COMMAND = toupper(getch());
        switch (_COMMAND) {
        case 27:
            InGameMenu();
            break;

        case 'A':
            if (_TURN) MoveLeft();  // X's turn
            break;
        case 'W':
            if (_TURN) MoveUp();
            break;
        case 'S':
            if (_TURN) MoveDown();
            break;
        case 'D':
            if (_TURN) MoveRight();
            break;

        case 13: { // Enter key
            if (CheckBoard(_X, _Y, 0) == -1) { // Valid X move
                cout << BACKGROUND_WHITE;
                cout << COLOR_RED << COLOR_BOLD << "X" << COLOR_RESET;
                moveXCount++;
                GotoXY(10, 12);
                cout << COLOR_RED "Moves player X: " << moveXCount << COLOR_RESET;
                moveMade = true;
                 // Switch to O's turn
                return true; // Exit the loop when move is made
            }
        }
        }
    }
    return false;
}

bool moveArrowLAN() {
    bool validEnter = true;
    bool moveMade = false;

    while (1) {  // Keep the loop for continuous movement
        _COMMAND = toupper(getch());
        switch (_COMMAND) {
        case 27:
            InGameMenu();
            break;

        case 75: // left
            if (!_TURN) MoveLeft();  // O's turn
            break;
        case 72: // up
            if (!_TURN) MoveUp();
            break;
        case 80: // down
            if (!_TURN) MoveDown();
            break;
        case 77: // right
            if (!_TURN) MoveRight();
            break;

        case 13: { // Enter key
            if (CheckBoard(_X, _Y, 0) == 1) { // Valid O move
                cout << BACKGROUND_WHITE;
                cout << COLOR_BLUE << COLOR_BOLD << "O" << COLOR_RESET;
                moveOCount++;
                GotoXY(93, 12);
                cout << COLOR_BLUE "Moves player O: " << moveOCount << COLOR_RESET;
                moveMade = true;
                // Switch to X's turn
                return true; // Exit the loop when move is made
            }
        }
        }
    }
    return false;
}