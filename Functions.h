#ifndef FUNCTIONS_H
#define FUNCTIONS_H



#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#pragma warning(disable:4996) 
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING



#define LEFT 36 // 3 toa do cua ban co
#define TOP 1 // 1
#define RIGHT LEFT+BOARD_SIZE*4
#define BOTTOM TOP+BOARD_SIZE*2
#define UP_KEY 72
#define DOWN_KEY 80
#define TOGGLE_KEY 32// phím Space
#define BACKSPACE_KEY 8
#define ENTER_KEY 13  // phím Enter
// kich thuoc mac dinh cua terminal la 120x30 tren may toi la the????? cai nay chinh duoc....

// 1 o co kich thuoc la 4x2 (ngang 4 dai 2)
#define BOARD_SIZE 12


//AI related variables
#define P1 4 //Red
#define P2 1 //Blue
#define VX 1
#define VO 2
#define _level 2 // AI search depth



#include <WinSock2.h>
#include <ws2tcpip.h>
#include <conio.h>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <algorithm>
#include <iomanip>



#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "winmm.lib") // de them hieu ung am thanh

using namespace std;
using namespace std::experimental::filesystem;

struct Cursor {
    COORD coord;
};

struct CursorRemove {
    COORD coord;
};

struct XO{
    COORD X[200], O[200];
    int nX = 0, nO = 0;
};


struct _POINT {
    int x , y, c;
    bool isMove;
};


struct GameState {
    _POINT move;
    int winner;  // -1: X wins, 1: O wins, 0: draw, 2: game continues
    bool acknowledged;
};


//Control
void StartGame();
void ExitGame();
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
// moi sua ten move wasd thanh gamemove
void GameMove();
void moveWASDAI();
bool moveArrowLAN();
bool moveWASDLAN();

//View
void GotoXY(int, int);
void FixConsoleWindow();
void setConsoleSize(int, int);
void HideCursor();
void AppearCursor();
void DrawBoard();
int ProcessFinish(int);
int AskContinue();
void DrawExistingXO();

//Menu
void MenuHandler();
void About();
void loadGame();
void saveGame();
void Guide();
void Settings();
void deleteOldestSaveFile();

void MenuNewGame();
void MenuOffline();
void MenuPVP();
bool sureExit();

void InGameMenu();
vector<string> GetSaveFiles();
string SelectSaveFile(bool);



//Model
void ResetData();
//void GarbageCollect();
int TestBoard(int);
int CheckBoard(int, int, int);
void changePlayer();
//Model-AI
void BoardToBoard(int, int); //copy board1 sang board2
// AI-related function prototypes
int AIHori(int, int, int);
int AIVerti(int, int, int);
int AIPCross(int, int, int);
int AIRCross(int, int, int);
int AIRepeat(int, int, int, int);
void AIPlay();



// Sound
void introSound();
void backgroundMusicSound();
void enterXSound();
void enterOSound();
void winSound();
void newGameSound();
void pickSound();
void exitSound();
void saveSound();
//void moveSound();





//LAN
void initWinsock();
void cleanupWinsock();
void startServer();
void startClient(const string& serverIP);
void serializePoint(const _POINT& point, char* buffer);
void deserializePoint(const char* buffer, _POINT& point);
void sendPoint(SOCKET sock, const _POINT& point);
void recvPoint(SOCKET sock, _POINT& point);
void LANcore(SOCKET sock, bool isHost);
void sendGameState(SOCKET sock, const GameState& state);
void recvGameState(SOCKET sock, GameState& state);




#endif
