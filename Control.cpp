#include "Functions.h"
#include "graphic.h"
#include "Color.h"

extern _POINT _A[3][BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;

extern bool backgroundMusicmode;
extern bool SFXmode;

void StartGame() {
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
                    enterXOSound();
                    break;
                
                case 1:
                    cout << BACKGROUND_WHITE;
                    cout << COLOR_BLUE << COLOR_BOLD<< "O" << COLOR_RESET;
                    enterXOSound();
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
                cout << "X";

                // AI Play
                AIPlay();

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
                        StartGame();
                    break;
                case 2:
                    // continue
                    break;
                }
                _TURN = -1;
                break;

            case 0:
                validEnter = false; //danh vao o dah roi
            }
            validEnter = true; // unlock
        }
        }
    }
}