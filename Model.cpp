#include "Functions.h"
#include "graphic.h"
#include "Color.h"

extern _POINT _A[3][BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;

void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[0][i][j].x = 4 * j + LEFT + 2;
			_A[0][i][j].y = 2 * i + TOP + 1;
			_A[0][i][j].c = 0;
		}
	}
	_TURN = true; _COMMAND = -1;
	_X = _A[0][0][0].x;
	_Y = _A[0][0][0].y;
}

//void GarbageCollect() {
//}

void changePlayer() {
    _TURN != _TURN;
}

int TestBoard(int boardIndex = 0) { //boardIndex bieu thi _level cua board
	bool boardFull = true;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[boardIndex][i][j].c == 0) {
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
			if (_A[boardIndex][i][j].c != 0 &&
				_A[boardIndex][i][j].c == _A[boardIndex][i][j + 1].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i][j + 2].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i][j + 3].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i][j + 4].c && j < (BOARD_SIZE - 4)) {  // j < 8 để j +4 ở dưới không quá (BOARD_SIZE - 1) (vì mảng từ 0 đến boardsize -1

				int mode;
				_A[boardIndex][i][j].c > 0 ? (mode = -1) : (mode = 1);

				nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 1) * 4, TOP + 1 + i * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 2) * 4, TOP + 1 + i * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 3) * 4, TOP + 1 + i * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 4) * 4, TOP + 1 + i * 2, mode);

				return (mode);
			}
		}
	}

	// check doc
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[boardIndex][i][j].c != 0 &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 1][j].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 2][j].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 3][j].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 4][j].c) {

				int mode;
				_A[boardIndex][i][j].c > 0 ? (mode = -1) : (mode = 1);

				nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, mode);
				nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 1) * 2, mode);
				nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 2) * 2, mode);
				nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 3) * 2, mode);
				nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 4) * 2, mode);

				return (mode);
			}
		}
	}

	// check cheo tren trai xuogn duoi phai
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[boardIndex][i][j].c != 0 &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 1][j + 1].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 2][j + 2].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 3][j + 3].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 4][j + 4].c && j < (BOARD_SIZE - 4)) {

				int mode;
				_A[boardIndex][i][j].c > 0 ? (mode = -1) : (mode = 1);

				nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 1) * 4, TOP + 1 + (i + 1) * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 2) * 4, TOP + 1 + (i + 2) * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 3) * 4, TOP + 1 + (i + 3) * 2, mode);
				nhapnhayXO(LEFT + 2 + (j + 4) * 4, TOP + 1 + (i + 4) * 2, mode);

				return (mode);
			}
		}
	}

	// check cheo tu tren phai xuong duoi trai
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[boardIndex][i][j].c != 0 &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 1][j - 1].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 2][j - 2].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 3][j - 3].c &&
				_A[boardIndex][i][j].c == _A[boardIndex][i + 4][j - 4].c && j < (BOARD_SIZE - 4) && (j - 4) >= 0) {

				int mode;
				_A[boardIndex][i][j].c > 0 ? (mode = -1) : (mode = 1);

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
//No animations
int TestWin() {
	bool boardFull = true;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[0][i][j].c == 0) {
				boardFull = false;
				break;
			}
		}
		if (!boardFull) break;
	}
	if (boardFull) return 0; // draw

	// check horizontal
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE - 4; j++) {
			if (_A[0][i][j].c != 0 &&
				_A[0][i][j].c == _A[0][i][j + 1].c &&
				_A[0][i][j].c == _A[0][i][j + 2].c &&
				_A[0][i][j].c == _A[0][i][j + 3].c &&
				_A[0][i][j].c == _A[0][i][j + 4].c) {
				return _A[0][i][j].c > 0 ? -1 : 1;
			}
		}
	}

	// check vertical
	for (int i = 0; i < BOARD_SIZE - 4; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[0][i][j].c != 0 &&
				_A[0][i][j].c == _A[0][i + 1][j].c &&
				_A[0][i][j].c == _A[0][i + 2][j].c &&
				_A[0][i][j].c == _A[0][i + 3][j].c &&
				_A[0][i][j].c == _A[0][i + 4][j].c) {
				return _A[0][i][j].c > 0 ? -1 : 1;
			}
		}
	}

	// check diagonal (top-left to bottom-right)
	for (int i = 0; i < BOARD_SIZE - 4; i++) {
		for (int j = 0; j < BOARD_SIZE - 4; j++) {
			if (_A[0][i][j].c != 0 &&
				_A[0][i][j].c == _A[0][i + 1][j + 1].c &&
				_A[0][i][j].c == _A[0][i + 2][j + 2].c &&
				_A[0][i][j].c == _A[0][i + 3][j + 3].c &&
				_A[0][i][j].c == _A[0][i + 4][j + 4].c) {
				return _A[0][i][j].c > 0 ? -1 : 1;
			}
		}
	}

	// check diagonal (top-right to bottom-left)
	for (int i = 0; i < BOARD_SIZE - 4; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			if (_A[0][i][j].c != 0 &&
				_A[0][i][j].c == _A[0][i + 1][j - 1].c &&
				_A[0][i][j].c == _A[0][i + 2][j - 2].c &&
				_A[0][i][j].c == _A[0][i + 3][j - 3].c &&
				_A[0][i][j].c == _A[0][i + 4][j - 4].c) {
				return _A[0][i][j].c > 0 ? -1 : 1;
			}
		}
	}

	return 2; // no winner yet
}

//Animations for lan
int TestBoardLAN() {
	int winner = TestWin();
	if (winner != 2) {
		// If there's a winner or draw, find and display the winning line
		if (winner != 0) { // Not a draw
			// check horizontal
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE - 4; j++) {
					if (_A[0][i][j].c != 0 &&
						_A[0][i][j].c == _A[0][i][j + 1].c &&
						_A[0][i][j].c == _A[0][i][j + 2].c &&
						_A[0][i][j].c == _A[0][i][j + 3].c &&
						_A[0][i][j].c == _A[0][i][j + 4].c) {

						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 1) * 4, TOP + 1 + i * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 2) * 4, TOP + 1 + i * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 3) * 4, TOP + 1 + i * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 4) * 4, TOP + 1 + i * 2, winner);
						return winner;
					}
				}
			}
			// check doc
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					if (_A[0][i][j].c != 0 &&
						_A[0][i][j].c == _A[0][i + 1][j].c &&
						_A[0][i][j].c == _A[0][i + 2][j].c &&
						_A[0][i][j].c == _A[0][i + 3][j].c &&
						_A[0][i][j].c == _A[0][i + 4][j].c) {

						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, winner);
						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 1) * 2, winner);
						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 2) * 2, winner);
						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 3) * 2, winner);
						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + (i + 4) * 2, winner);

						return winner;
					}
				}
			}

			// check cheo tren trai xuogn duoi phai
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					if (_A[0][i][j].c != 0 &&
						_A[0][i][j].c == _A[0][i + 1][j + 1].c &&
						_A[0][i][j].c == _A[0][i + 2][j + 2].c &&
						_A[0][i][j].c == _A[0][i + 3][j + 3].c &&
						_A[0][i][j].c == _A[0][i + 4][j + 4].c && j < (BOARD_SIZE - 4)) {

						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 1) * 4, TOP + 1 + (i + 1) * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 2) * 4, TOP + 1 + (i + 2) * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 3) * 4, TOP + 1 + (i + 3) * 2, winner);
						nhapnhayXO(LEFT + 2 + (j + 4) * 4, TOP + 1 + (i + 4) * 2, winner);

						return winner;
					}
				}
			}

			// check cheo tu tren phai xuong duoi trai
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					if (_A[0][i][j].c != 0 &&
						_A[0][i][j].c == _A[0][i + 1][j - 1].c &&
						_A[0][i][j].c == _A[0][i + 2][j - 2].c &&
						_A[0][i][j].c == _A[0][i + 3][j - 3].c &&
						_A[0][i][j].c == _A[0][i + 4][j - 4].c && j < (BOARD_SIZE - 4) && (j - 4) >= 0) {

						nhapnhayXO(LEFT + 2 + j * 4, TOP + 1 + i * 2, winner);
						nhapnhayXO(LEFT + 2 + (j - 1) * 4, TOP + 1 + (i + 1) * 2, winner);
						nhapnhayXO(LEFT + 2 + (j - 2) * 4, TOP + 1 + (i + 2) * 2, winner);
						nhapnhayXO(LEFT + 2 + (j - 3) * 4, TOP + 1 + (i + 3) * 2, winner);
						nhapnhayXO(LEFT + 2 + (j - 4) * 4, TOP + 1 + (i + 4) * 2, winner);

						return (winner);
					}

				}
			}
		}
	}
	return winner;
}

int CheckBoard(int pX, int pY, int boardIndex = 0) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[boardIndex][i][j].x == pX &&
				_A[boardIndex][i][j].y == pY &&
				_A[boardIndex][i][j].c == 0) {
				if (_TURN == true)
					_A[boardIndex][i][j].c = -1;
				else
					_A[boardIndex][i][j].c = 1;
				return _A[boardIndex][i][j].c;
			}
		}
	}
	return 0;
}

void BoardToBoard(int b1, int b2)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[b2][i][j].x = _A[b1][i][j].x;     // copy x coordinate
			_A[b2][i][j].y = _A[b1][i][j].y;     // copy y coordinate
			_A[b2][i][j].c = _A[b1][i][j].c;     // copy cell state
		}
	}
}

int AIHori(int x, int y, int cboard) {
	int player = _A[cboard][x][y].c;
	int count = -1;
	int opcount = 0;

	// check left side
	for (int i = x; i >= 0; i--) {
		if (_A[cboard][y][i].c == player) count++;
		else if (_A[cboard][y][i].c != 0) {
			opcount++;
			break;
		}
		else break;
	}

	// check right side
	for (int i = x + 1; i < BOARD_SIZE; i++) {
		if (_A[cboard][y][i].c == player) count++;
		else if (_A[cboard][y][i].c != 0) {
			opcount++;
			break;
		}
		else break;
	}

	if (opcount >= 2 && count > opcount) return count - opcount;
	if (opcount >= 2) return 0;
	return count;
}



int AIVerti(int x, int y, int cboard)
{
	int player = _A[cboard][x][y].c;
	int count = -1;
	int opcount = 0;


	// check up
	for (int i = y; i >= 0; i--) {
		if (_A[cboard][i][x].c == player) count++;
		else if (_A[cboard][i][x].c != 0) {
			opcount++;
			break;
		}
		else break;
	}

	// check down
	for (int i = y + 1; i < BOARD_SIZE; i++) {
		if (_A[cboard][i][x].c == player) count++;
		else if (_A[cboard][i][x].c != 0) {
			opcount++;
			break;
		}
		else break;
	}

	if (opcount >= 2 && count > opcount) return count - opcount;
	if (opcount >= 2) return 0;
	return count;
}


int AIPCross(int x, int y, int cboard)
{
	int player = _A[cboard][x][y].c;
	int count = -1;
	int opcount = 0;



	int m = min(x, y);
	for (int i = 0; i <= m; i++)
	{
		if (_A[cboard][y - i][x + i].c == player) count++;
		else if (_A[cboard][y - i][x + i].c != 0)
		{
			opcount++;
			break;
		}
		else break;
	}


	m = min(BOARD_SIZE, BOARD_SIZE);
	for (int i = 1;i <= m; i++)
	{
		if (_A[cboard][y + i][x - i].c == player) count++;
		else if (_A[cboard][y + i][x - i].c != 0)
		{
			opcount++;
			break;
		}
		else break;
	}
	if (opcount >= 2 && count > opcount) return count - opcount;
	if (opcount >= 2) return 0;
	return count;
}



int AIRCross(int x, int y, int cboard)
{
	int player = _A[cboard][x][y].c;
	int count = -1;
	int opcount = 0;



	int m = min(x, BOARD_SIZE - y);
	for (int i = 0; i <= m; i++)
	{
		if (_A[cboard][y - i][x - i].c == player)
			count++;
		else if (_A[cboard][y - i][x - i].c != 0)
		{
			opcount++;
			break;
		}
		else break;
	}


	m = min(BOARD_SIZE - x, y);
	for (int i = 1;i <= m; i++)
	{
		if (_A[cboard][y + i][x + i].c == player)
			count++;
		else if (_A[cboard][y + i][x + i].c != 0)
		{
			opcount++;
			break;
		}
		else break;
	}
	if (opcount >= 2 && count > opcount)
		return count - opcount;
	if (opcount >= 2)
		return 0;
	return count;
}



//Thuat toan AI minimax
int _AtkArray[9] = { 0,1,2,7,100,200,210,220,230 };
int _DefArray[9] = { 0,1,2,7,30,40,50,60,70 };

int AIRepeat(int x, int y, int pl, int b) {
	int max = -9999;
	BoardToBoard(b - 1, b);

	// duoi day la de con bot no mo phong nuoc di
	// truoc het la no mo phong nuoc di cua doi thu
	// cai duoi day la de no doi nguoi choi so voi nguoi hien tai, vi du minh dang la x thi se doi sang o de ma mo phong
	_A[b][x][y].c = (P1 + P2) - pl;

	int scoreDef = _DefArray[AIHori(x, y, b)] +
		_DefArray[AIVerti(x, y, b)] +
		_DefArray[AIPCross(x, y, b)] +
		_DefArray[AIRCross(x, y, b)];

	// tuong tu
	_A[b][x][y].c = pl;

	//duoi day la he thong tinh diem de con bot no dua theo do ma mo phong
	int scoreAtk = _AtkArray[AIHori(x, y, b)] +
		_AtkArray[AIVerti(x, y, b)] +
		_AtkArray[AIPCross(x, y, b)] +
		_AtkArray[AIRCross(x, y, b)];

	int score = scoreDef + scoreAtk;

	if (b < _level) { //_level la depth de con bot no tim duong cang cao no cang khon
		int sc;
		for (int x1 = 0; x1 < BOARD_SIZE; x1++) {
			for (int y1 = 0; y1 < BOARD_SIZE; y1++) {
				if (_A[b][x1][y1].c == 0) {
					sc = AIRepeat(x1, y1, (P1 + P2) - pl, b + 1); // de quy de tim duoc nuoc tot nhat trong cai depth
					if (sc > max) max = sc;
				}
			}
		}
		score += max;
	}

	return (pl == P2) ? -score : score;
}


//Ham de con bot no play
void AIPlay() {
	int score;
	int max = -9999;
	int cx = 0, cy = 0;
	_TURN = false;

	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			if (_A[0][x][y].c == 0) {
				BoardToBoard(0, 1);
				score = AIRepeat(x, y, -1, 1);  // -1 la cho x, do nguoi choi luon la X

				if (score > max) {
					max = score;
					cx = x;
					cy = y;
				}
			}
		}
	}

	// cho con ai danh
	_X = _A[0][cx][cy].x;
	_Y = _A[0][cx][cy].y;
	CheckBoard(_X, _Y, 0);
	GotoXY(_X, _Y);
	cout << BACKGROUND_WHITE;
	cout << COLOR_BLUE << COLOR_BOLD << "O" << COLOR_RESET;
	enterOSound();
}
