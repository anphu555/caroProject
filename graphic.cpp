#include "graphic.h"
#include "Functions.h"
#include "Color.h"

void CaroLogo(int x, int y)
{
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, luu vô để hồi đổi lại
	// tạo biến logo caro
	wstring logo[8];
	logo[0] = L"   ▄▄██▀▀▀  ▄█████▄   ▄█████▄  ▀ ▄██████▄ ";
	logo[1] = L"█ ▄██▀    ▀      ███  ██▀  ▀██  ██▀    ▀██";
	logo[2] = L"  ██              ██  ██   ▄██  ██      ██";
	logo[3] = L"  ██   ▀    ▄████▄██  ██▄███▀   ██  ██  ██";
	logo[4] = L"  ██       ██▀   ▀██  ██▀█▄     ██      ██";
	logo[5] = L"  ▀██▄     ██▄ ▀ ▄██  ██ ▀██▄   ██▄    ▄██";
	logo[6] = L" ▀  ▀▀██▄▄▄ ▀█████▀▀  ██   ▀██▄▄ ▀██████▀ ";
	logo[7] = L"                     ▄██                  ";
	//logo[8] = L"       ▀       ▀              ▀       ";
	// in logo caro
	for (int i = 0; i < 8; i++)
	{
        GotoXY(x, y + i);
		wcout << logo[i];
	}
    int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void MenuLogo1(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	// Tạo biến cây thông
	wstring tree[12] = {
		L"        █         ",
		L"       ███        ",
		L"      █████       ",
		L"     ███████      ",
		L"    █████████     ",
		L"   ███████████    ",
		L"  █████████████   ",
		L" ███████████████  ",
		L"█████████████████ ",
		L"       ███        ",
		L"       ███        ",
		L"       ███        "
	};

	// In cây thông
	for (int i = 0; i < 12; i++)
	{
		GotoXY(x, y + i);
		wcout << tree[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void MenuLogo2(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	// Tạo biến ông già Noel
	wstring logo[11] = {
	L"	_.█████████████████",
L"_ ██████████████████",
L"████████████████████",
L"█████████████████████",
L"_█_________▄▄▄▄_ ▄▄▄▄_█",
L"_█__█████_▐▓▓▌_▐▓▓▌_█",
L"_█__█████_▐▓▓▌_▐▓▓▌_█",
L"_█__█████_▐▓▓▌_▐▓▓▌_█",
L"_█__█████_▀▀▀▀_ ▀▀▀▀ █✿ ✿",
L"_█__█████_____________ █(\\|/)",
L"_____________██ _____________██"
    };

	// In ông già Noel
	for (int i = 0; i < 11; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void IngameLogo(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6];
	logo[0] = L"╔═╗╔═╦═══╗";
	logo[1] = L"╚╗╚╝╔╣╔═╗║";
	logo[2] = L" ╚╗╔╝║║▒║║";
	logo[3] = L" ╔╝╚╗║║▒║║";
	logo[4] = L"╔╝╔╗╚╣╚═╝║";
	logo[5] = L"╚═╝╚═╩═══╝";

	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}


void IngameLogo4(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6];
	logo[0] = L"████████╗██╗░░██╗███████╗░░█████╗░░█████╗░██████╗░░█████╗░░░██████╗░░█████╗░███╗░░░███╗███████╗";
	logo[1] = L"╚══██╔══╝██║░░██║██╔════╝░██╔══██╗██╔══██╗██╔══██╗██╔══██╗░██╔════╝░██╔══██╗████╗░████║██╔════╝";
	logo[2] = L"░░░██║░░░███████║█████╗░░░██║░░╚═╝███████║██████╔╝██║░░██║░██║░░██╗░███████║██╔████╔██║█████╗░░";
	logo[3] = L"░░░██║░░░██╔══██║██╔══╝░░░██║░░██╗██╔══██║██╔══██╗██║░░██║░██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░";
	logo[4] = L"░░░██║░░░██║░░██║███████╗░╚█████╔╝██║░░██║██║░░██║╚█████╔╝░╚██████╔╝██║░░██║██║░╚═╝░██║███████╗";
	logo[5] = L"░░░╚═╝░░░╚═╝░░╚═╝╚══════╝░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝";

	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_RED << COLOR_BOLD << logo[i] << " " << COLOR_RESET;
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}


void IngameLogo2(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6];
	logo[0] = L"╔════╦╗▒╔╦═══╗╔═══╦═══╦═══╦═══╗╔═══╦═══╦═╗╔═╦═══╗";
	logo[1] = L"║╔╗╔╗║║▒║║╔══╝║╔═╗║╔═╗║╔═╗║╔═╗║║╔═╗║╔═╗║║╚╝║║╔══╝";
	logo[2] = L"╚╝║║╚╣╚═╝║╚══╗║║▒╚╣║▒║║╚═╝║║▒║║║║▒╚╣║▒║║╔╗╔╗║╚══╗";
	logo[3] = L"▒▒║║▒║╔═╗║╔══╝║║▒╔╣╚═╝║╔╗╔╣║▒║║║║╔═╣╚═╝║║║║║║╔══╝";
	logo[4] = L"▒▒║║▒║║▒║║╚══╗║╚═╝║╔═╗║║║╚╣╚═╝║║╚╩═║╔═╗║║║║║║╚══╗";
	logo[5] = L"▒▒╚╝▒╚╝▒╚╩═══╝╚═══╩╝▒╚╩╝╚═╩═══╝╚═══╩╝▒╚╩╝╚╝╚╩═══╝";
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}//cai nay se tach ra lam x voi o roi de 2 ben
void IngameLogo3(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6];
	logo[0] = L"██╗░░██╗ ░█████╗░";
	logo[1] = L"╚██╗██╔╝ ██╔══██╗";
	logo[2] = L"░╚███╔╝ ░██║░░██║";
	logo[3] = L"░██╔██╗ ░██║░░██║║";
	logo[4] = L"██╔╝╚██╗ ╚█████╔╝";
	logo[5] = L"╚═╝░░╚═╝ ░╚════╝░";
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}


void AboutLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, luu vô để hồi đổi lại

	// tạo biến 
	wstring logo[9];//==============

	// in logo caro
	for (int i = 0; i < 9; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void WinEffect(int x, int y, int Mode) {
	HideCursor();
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // Đổi chế độ ghi Unicode

	// Tạo biến logo chiến thắng
	wstring OWin[6] = {
		L" ██████╗     ██╗    ██╗██╗███╗   ██╗",
		L"██╔═══██╗    ██║    ██║██║████╗  ██║",
		L"██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║",
		L"██║   ██║    ██║███╗██║██║██║╚██╗██║",
		L"╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║",
		L" ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝"
	};

	wstring XWin[6] = {
		L"██╗  ██╗    ██╗    ██╗██╗███╗   ██╗",
		L"╚██╗██╔╝    ██║    ██║██║████╗  ██║",
		L" ╚███╔╝     ██║ █╗ ██║██║██╔██╗ ██║",
		L" ██╔██╗     ██║███╗██║██║██║╚██╗██║",
		L"██╔╝ ██╗    ╚███╔███╔╝██║██║ ╚████║",
		L"╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝"
	};

	wstring Draw[6] = {
		L"██████╗ ██████╗  █████╗ ██╗    ██╗",
		L"██╔══██╗██╔══██╗██╔══██╗██║    ██║",
		L"██║  ██║██████╔╝███████║██║ █╗ ██║",
		L"██║  ██║██╔══██╗██╔══██║██║███╗██║",
		L"██████╔╝██║  ██║██║  ██║╚███╔███╔╝",
		L"╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ "
	};

	// Phát âm thanh chiến thắng
	winSound();

	// Hiệu ứng chớp nháy
	for (int blink = 0; blink < 7; ++blink) { // Chớp nháy 7 lần
		

		for (int i = 0; i < 6; i++) {
			GotoXY(x, y + i);
			wcout << L"                                   ";
		}
		Sleep(150);

		// Hiển thị logo
		for (int i = 0; i < 6; i++) {
			
			GotoXY(x, y + i);
			switch (Mode) {
			case -1:
				wcout << COLOR_BLUE<< OWin[i] << COLOR_RESET;
				break;
			case 1:
				wcout << COLOR_RED<< XWin[i] << COLOR_RESET;
				break;
			case 0:
				wcout << COLOR_GREEN << Draw[i] << COLOR_RESET;
				break;
			}
		}
		// Dừng lại một khoảng thời gian
		Sleep(100);	
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	AppearCursor();

	return;
}

void nhapnhayXO(int x, int y, int mode) // mode -1 o, 1 x, 0draw
{
	HideCursor();

	//if (mode == 0) return; do draw thi khong nhap nhay
	for (int blink = 0; blink < 3; blink++)
	{
		GotoXY(x, y); cout << ' ';
		Sleep(70);

		// in x ra
		GotoXY(x, y);
		switch (mode)
		{
		case 1:
			cout << COLOR_RED COLOR_BOLD BACKGROUND_RED COLOR_DARK << "X" << COLOR_RESET;
			break;
		case -1:
			cout << COLOR_BLUE COLOR_BOLD BACKGROUND_CYAN COLOR_DARK << "O" << COLOR_RESET;
			break;
		}

		Sleep(50);

		// làm mất chữ
	}
}

void XLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[7] = {
		L"    ██╗░░██╗",
		L"    ╚██╗██╔╝",
		L"    ░╚███╔╝░",
		L"    ░██╔██╗░",
		L"    ██╔╝╚██╗",
		L"    ╚═╝░░╚═╝"
	};

	for (int i = 0; i < 11; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_RED << logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void OLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[7] = {
		L"    ░█████╗░",
		L"    ██╔══██╗",
		L"    ██║░░██║",
		L"    ██║░░██║",
		L"    ╚█████╔╝",
		L"    ░╚════╝░"
	};

	for (int i = 0; i < 11; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_BLUE << logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

//void openingScreen(int x, int y)
//{
//	CaroLogo(50, 50);
//
//}
void AnimatedSquare(int xleft, int xright, int ytop, int ybottom)
{
	for (int i = xleft; i <= xright; i++) // để cho nó chạy từ 0
	{
		GotoXY(i, ytop); cout << char(220); // 220
		GotoXY(xright - i, ybottom); cout << char(223);//223
		Sleep(50);
	}
	//for (int i = (ytop+1); i <= (ybottom-1); i++) // để cho nó chạy từ 0
	//{
	//	++i;
	//	GotoXY(xleft, i); cout << char(219); //221
	//	GotoXY(xright , ybottom - i); cout << char(219); //222
	//	Sleep(10);
	//}
	
	//for (int i = 0; i < D2_ABOUT_1.size() - 1 - i; i += 2) {
	//	gotoxy(_pos_x + i, D2_Y_ABOUT - 7);
	//	wcout << L"▜";
	//	gotoxy(_pos_x + i, D2_Y_ABOUT - 6);
	//	wcout << D2_ABOUT_2[i] << D2_ABOUT_2[i + 1];
	//	gotoxy(_pos_x + i, D2_Y_ABOUT - 5);
	//	wcout << D2_ABOUT_3[i] << D2_ABOUT_3[i + 1];
	//	gotoxy(_pos_x + i, D2_Y_ABOUT - 4);
	//	wcout << D2_ABOUT_4[i] << D2_ABOUT_4[i + 1];
	//	gotoxy(_pos_x + i, D2_Y_ABOUT - 3);
	//	wcout << D2_ABOUT_5[i] << D2_ABOUT_5[i + 1];
	//	gotoxy(_pos_x + i, D2_Y_ABOUT - 2);
	//	wcout << D2_ABOUT_6[i] << D2_ABOUT_6[i + 1];

	//	gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 7);
	//	wcout << D2_ABOUT_1[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_1[D2_ABOUT_1.size() - 1 - i];
	//	gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 6);
	//	wcout << D2_ABOUT_2[int(D2_ABOUT_1.size()) - 2 - i] << D2_ABOUT_2[D2_ABOUT_1.size() - 1 - i];
	//	gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 5);
	//	wcout << D2_ABOUT_3[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_3[D2_ABOUT_1.size() - 1 - i];
	//	gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 4);
	//	wcout << D2_ABOUT_4[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_4[D2_ABOUT_1.size() - 1 - i];
	//	gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 3);
	//	wcout << D2_ABOUT_5[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_5[D2_ABOUT_1.size() - 1 - i];
	//	gotoxy(_pos_x + int(D2_ABOUT_1.size()) - i - 2, D2_Y_ABOUT - 2);
	//	wcout << D2_ABOUT_6[D2_ABOUT_1.size() - 2 - i] << D2_ABOUT_6[D2_ABOUT_1.size() - 1 - i];

	//	Sleep(10);
	//}
}
