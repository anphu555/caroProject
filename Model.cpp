#include "Functions.h"
#include "graphic.h"

extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;

void ResetData() {
    for(int i = 0 ; i < BOARD_SIZE ; i++){
        for(int j = 0 ; j < BOARD_SIZE ; j++){
            _A[i][j].x = 4 * j + LEFT + 2; 
            _A[i][j].y = 2 * i + TOP + 1; 
            _A[i][j].c = 0; 
        }
    }
    _TURN = true; _COMMAND = -1; 
    _X = _A[0][0].x; _Y = _A[0][0].y; 
}

//void GarbageCollect() {
//}

int TestBoard() {
    bool boardFull = true;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].c == 0) {
                boardFull = false;
                break;
            }
        }
        if (!boardFull) break;
    }
    if (boardFull) return 0; // draw

    // check ngang
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].c != 0 &&
                _A[i][j].c == _A[i][j+1].c &&
                _A[i][j].c == _A[i][j+2].c &&
                _A[i][j].c == _A[i][j+3].c &&
                _A[i][j].c == _A[i][j+4].c) {

                int mode;
                _A[i][j].c > 0 ? (mode = -1) : (mode = 1);

                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+1) * 4, TOP + 1 + i * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+2) * 4, TOP + 1 + i * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+3) * 4, TOP + 1 + i * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+4) * 4, TOP + 1 + i * 2, mode);

                return (mode);
                }
        }
    }

    // check doc
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j <BOARD_SIZE; j++) {
            if (_A[i][j].c != 0 &&
                _A[i][j].c == _A[i+1][j].c &&
                _A[i][j].c == _A[i+2][j].c &&
                _A[i][j].c == _A[i+3][j].c &&
                _A[i][j].c == _A[i+4][j].c) {

                int mode;
                _A[i][j].c > 0 ? (mode = -1) : (mode = 1);

                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, mode);
                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i+1) * 2, mode);
                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i+2) * 2, mode);
                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i+3) * 2, mode);
                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i+4) * 2, mode);

                    return (mode);
                }
        }
    }

    // check cheo tren trai xuogn duoi phai
    for (int i = 0; i < BOARD_SIZE ; i++ ) {
        for (int j = 0; j < BOARD_SIZE ; j++) {
            if(_A[i][j].c != 0 && 
               _A[i][j].c == _A[i+1][j+1].c &&
               _A[i][j].c == _A[i+2][j+2].c &&
               _A[i][j].c == _A[i+3][j+3].c &&
               _A[i][j].c == _A[i+4][j+4].c) {

                int mode;
                _A[i][j].c > 0 ? (mode = -1) : (mode = 1);

                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+1) * 4, TOP + 1 + (i+1) * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+2) * 4, TOP + 1 + (i+2) * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+3) * 4, TOP + 1 + (i+3) * 2, mode);
                nhapnhayXO(LEFT + 2 + (j+4) * 4, TOP + 1 + (i+4) * 2, mode);

                return (mode);
               }
        }
    }

    // check cheo tu tren phai xuong duoi trai
    for (int i = 0; i < BOARD_SIZE ; i++ ) {
        for (int j = 0; j < BOARD_SIZE ; j++) {
            if(_A[i][j].c != 0 && 
               _A[i][j].c == _A[i+1][j-1].c &&
               _A[i][j].c == _A[i+2][j-2].c &&
               _A[i][j].c == _A[i+3][j-3].c &&
               _A[i][j].c == _A[i+4][j-4].c) {

                int mode;
                _A[i][j].c > 0 ? (mode = -1) : (mode = 1);

                nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, mode);
                nhapnhayXO(LEFT + 2 + (j - 1) * 4, TOP + 1 + (i + 1) * 2, mode);
                nhapnhayXO(LEFT + 2 + (j - 2) * 4, TOP + 1 + (i + 2) * 2, mode);
                nhapnhayXO(LEFT + 2 + (j - 3) * 4, TOP + 1 + (i + 3) * 2, mode);
                nhapnhayXO(LEFT + 2 + (j - 4) * 4, TOP + 1 + (i + 4) * 2, mode);

                return (mode);
               }
        }
    }

    // k co gi thi tiep
    return 2;
}

int CheckBoard(int pX, int pY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
                if (_TURN == true) _A[i][j].c = -1;
                else _A[i][j].c = 1;
                return _A[i][j].c;
            } 
        }
    }
    return 0;
}