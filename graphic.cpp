#include "graphic.h"
#include "Functions.h"
#include "Color.h"

void CaroLogo(int x, int y)
{
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, luu vô để hồi đổi lại
	// tạo biến logo caro
	wstring logo[9];
	logo[0] = L"   ▄▄██▀▀▀  ▄█████▄   ▄█████▄  ▀ ▄██████▄ ";
	logo[1] = L"█ ▄██▀    ▀      ███  ██▀  ▀██  ██▀    ▀██";
	logo[2] = L"  ██              ██  ██   ▄██  ██      ██";
	logo[3] = L"  ██   ▀    ▄████▄██  ██▄███▀   ██  ██  ██  ▀ ";
	logo[4] = L"  ██       ██▀   ▀██  ██▀█▄     ██      ██";
	logo[5] = L"  ▀██▄     ██▄ ▀ ▄██  ██ ▀██▄   ██▄    ▄██";
	logo[6] = L" ▀  ▀▀██▄▄▄ ▀█████▀▀  ██   ▀██▄▄ ▀██████▀ ";
	logo[7] = L"                     ▄██                  ";
	logo[8] = L"       ▀       ▀              ▀       ";
	// in logo caro
	for (int i = 0; i < 9; i++)
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
		// Hiển thị logo
		/*system("color 9");
		cout << " "<<endl;
		system("color A");
		cout << " "<<endl;
		system("color B");
		cout << " "<<endl;
		system("color C");
		cout << " "<<endl;
		system("color D");
		cout << " " <<endl;*/
		for (int i = 0; i < 6; i++) {
			
			GotoXY(x, y + i);
			switch (Mode) {
			case -1:
				wcout << COLOR_BLUE<< OWin[i];
				break;
			case 1:
				wcout << COLOR_RED<< XWin[i];
				break;
			case 0:
				wcout << COLOR_CYAN << Draw[i];
				break;
			}
		}
		// Dừng lại một khoảng thời gian
		//this_thread::sleep_for(chrono::milliseconds(300));
		Sleep(300);
		
		for (int i = 0; i < 6; i++) {
			GotoXY(x, y + i);
			wcout << L"                                   "; 
			//Sleep(100);
		}
		Sleep(180);
		//this_thread::sleep_for(chrono::milliseconds(300));
	}

	// in lại cho khỏi mất sau khi nhấp
	for (int i = 0; i < 6; i++) {
		GotoXY(x, y + i);
		switch (Mode) {
		case -1:
			wcout << OWin[i];
			break;
		case 1:
			wcout << XWin[i];
			break;
		case 0:
			wcout << Draw[i];
			break;
		}
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	AppearCursor();

	return;
}
