#include "Functions.h"

_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;

int main() {
    // TAM thoi de BACKGROUND TIM (background_magneta)

    // chua tao duoc kich thuoc cua so choi game (bao nhieu pixel)

    FixConsoleWindow();
    MenuHandler();
    return 0;
}
