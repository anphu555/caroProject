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

// intro =====================================
void intro1(int x, int y) {
	system("color 0f");
	HideCursor();
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // Đổi chế độ ghi Unicode

	// Tạo biến logo chiến thắng
	wstring Group10[6] = {
		L" ██████╗ ██████╗  █████╗ ██╗   ██╗██████╗    ███╗   █████╗ ",
		L"██╔════╝ ██╔══██╗██╔══██╗██║   ██║██╔══██╗  ████║  ██╔══██╗",
		L"██║  ██╗ ██████╔╝██║  ██║██║   ██║██████╔╝ ██╔██║  ██║  ██║",
		L"██║  ╚██╗██╔══██╗██║  ██║██║   ██║██╔═══╝  ╚═╝██║  ██║  ██║",
		L"╚██████╔╝██║  ██║╚█████╔╝╚██████╔╝██║      ███████╗╚█████╔╝",
		L" ╚═════╝ ╚═╝  ╚═╝ ╚════╝  ╚═════╝ ╚═╝      ╚══════╝ ╚════╝ "
	};
		
	// Phát intro sound
	introSound();

	Sleep(320);

	// Hiển thị logo
	for (int i = 0; i < 6; i++) {
		GotoXY(x, y + i);
		wcout << COLOR_WHITE << Group10[i];
	}
	// Dừng lại một khoảng thời gian
	
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	Sleep(1600);

	return;
}

void intro2(int x, int y) {
	system("color 0f");
	HideCursor();
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // Đổi chế độ ghi Unicode

	// Tạo biến logo chiến thắng
	wstring Group10[27] = {
		L"⠀ ⠀⠀⠀⠀ ⣸⣿⣧⢹⣾⣴⣿⠋⡇⢸⣸⣿⣿⣿⣿⣿⣿⣯⣶⠟⠋⢀⣴⣫⢏⣴⠟⣽⣿⡟⠀⠈⢹⣿⣟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"⠀⠀⠀ ⠀⠀ ⢳⠇⣿⣿⣿⣿⢹⡀⠃⢸⡜⣿⢹⣿⣷⣿⣿⡿⣷⠶⠚⠛⢛⡿⠋⣠⣾⣿⣿⣤⣦⣀⢸⡟⣠⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"⠀ ⠀ ⠀⠀⢠⡞⣸⢻⣿⣿⣿⣾⣗⠄⠘⡇⣿⠚⠻⠿⠯⠿⠅⠀⠠⢄⠍⢨⡙⠊⠑⣿⣿⣯⣿⡿⠻⣿⢡⠇⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"⠀⠀ ⠀ ⠀⣾⢣⡟⢸⠀⣿⣿⣷⣿⣦⠀⣷⣹⣣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠛⠿⠿⡿⣁⣼⣿⡟⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"     ⢠⣇⣼⣿⣾⠀⣿⣿⣮⡛⢿⣧⣽⡿⣿⣷⡤⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠀⠶⠆⣰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"⠀⠀  ⠀⡼⣼⣿⡏⡟⣼⣿⣿⣿⡻⣿⠃⣸⡟⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"⠀  ⠀⢰⢳⢻⡿⣠⡷⣿⣿⣿⣿⡏⢻⣴⠏⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⣼⣿⡛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⠀⠀⡞⡞⣼⣷⢻⡇⣸⣿⣿⣿⡿⡟⠅⣴⣿⡟⢤⣀⠀⠀⠀⠀⠈⢿⡟⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣷⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⠀⢠⢻⢁⡿⠇⣸⠇⣿⣿⣿⣿⣇⣿⠞⣡⣿⣧⣤⣽⣷⣀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣿⣿⣿⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⠀⠀⡞⣸⠃⢀⣿⢀⣿⣿⣿⣿⣿⢥⣾⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⣀⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠁⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⠒⠺⠷⣏⡀⣼⡿⢸⣿⣿⣿⣏⣥⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣯⠀⠀⠀⠀⣀⠀⣿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠻⣿⣿",
		L"⠀  ⠀⠀⠀⠈⠙⠳⢿⣿⣿⡟⢉⣰⣿⣿⣿⣿⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠻⢿⣿⣿⣷⣤⠖⠛⠉⠉⠀⠀⢸⡏⠁⠀⠀⠀⠀⠀⠀⣿⣿",
		L"	⠀⠀⠀⠀⠤⢄⣀⠀⣨⡿⠟⢋⣿⡿⢯⣶⣝⣛⣛⣿⠿⢿⣿⢥⣠⠼⠻⣿⣟⣿⣿⣿⢿⣿⣿⡋⢤⡀⠀⠻⣌⣉⣻⣦⣀⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿",
		L"	⠀⠀⠀⠀⠀⠀⢀⣼⡟⠛⣛⣿⡿⠀⠉⢛⣻⣿⠿⠋⠀⢸⢹⠀⠀⠀⠀⠘⣾⣦⠉⠛⠷⢿⣿⣻⣦⡌⠢⡀⠘⣧⣙⡛⣿⣗⡚⠉⠉⠉⡇⠀⠀⢀⣀⣀⣠⣴⣿⣿",
		L"	⠀⠀⠀⢀⡤⡶⣿⠋⣽⠛⣿⡿⢁⣤⢶⡋⠉⠁⠀⠀⠀⢸⠾⠆⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠈⠙⠛⣿⣦⡙⣏⠁⠈⣯⣙⠛⢿⣆⠀⣼⣷⣶⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⠀⠀⢠⡟⢸⣷⣿⠉⡇⢀⣯⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠻⢿⣟⢧⡤⠶⠛⠋⠉⠻⣿⣽⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⣴⣶⣿⣧⣿⢃⠏⠀⡇⣼⣿⠟⠁⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠲⠤⣀⠀⠀⠀⢻⡝⢿⣾⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⣿⣿⣟⢿⣯⣎⠤⠔⡇⡿⠃⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠲⢴⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿⣿⣿",
		L"	⠀⣿⣿⡄⢿⠦⠀⢠⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢄⡉⢿⣻⡄⢻⣿⣿⣿⣿⣿⣿⣿",
		L"	⠀⢸⣿⣿⣾⣇⠀⠋⡏⠀⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠹⣵⡟⠙⠛⢿⣿⣿⣿⣿",
		L"	⣴⣿⣿⣿⣻⣿⣆⢰⠁⠀⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⢻⣠⣴⠀⣼⡟⠛⠛⠛",
		L"	⣿⣟⠙⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣾⣿⠁⠀⠀⠀",
		L"	⡏⠁⠀⠘⢿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠀⠀⢠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠃⠀⠀⠀⠀",
		L"	⣄⠀⢀⡀⠈⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⠃⠀⠀⠈⠻⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣷⣤⣀⠀⠀⠀",
		L"	⣿⣷⣌⢿⣷⣍⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠃⠀⠀⠀⠀⠈⠊⣙⠷⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⡟⣎⣻⣼⣷⡆⠀",
		L"	⣿⣿⣿⣷⣽⣿⣿⣿⣷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠙⠊⠉⠛⠷⢶⣤⣄⠀⠀⠀⢀⣠⣼⣿⣿⣿⣿⣷⣿⣿⡿⠿⠃⠀"
	};

	// Phát intro sound
	introSound();

	Sleep(320);

	// Hiển thị logo
	for (int i = 0; i < 27; i++) {
		GotoXY(x, y + i);
		wcout << COLOR_WHITE << Group10[i];
	}
	// Dừng lại một khoảng thời gian

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	Sleep(1600);

	return;
}



void introLoading() {
	system("cls");
	system("color f0");
	HideCursor();

	//IngameLogo4(14, 9);

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
		GotoXY(14, 9 + i);
		wcout << COLOR_RED COLOR_BOLD << logo[i] << " " << COLOR_RESET;
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);


	GotoXY(56, 19);
	printf(COLOR_ITALIC COLOR_BOLD COLOR_GREEN "Loading..." );
	BorderSquare(30, 90, 20, 20, 16);
	cout << COLOR_RESET BACKGROUND_WHITE;

	Sleep(500);

	return;
}
// ===========================================

void MenuLogoTree1(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	// Tạo biến cây thông
	wstring tree[10] = {
		L"      \u001b[32m█████     ",
		L"    █████████   ",
		L"   ███████████  ",
		L"   ███████████  ",
		L"  █████████████ ",
		L" ███████████████",
		L"       \u001b[2;33m███      ",
		L"       ███      ",
		L"       ███      ",
		L"       ███      "
	};

	// In cây thông
	for (int i = 0; i < 9; i++)
	{
		GotoXY(x, y + i);
		wcout << tree[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_RESET BACKGROUND_CYAN;
}

void MenuLogoTree2(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	// Tạo biến cây thông
	wstring tree[13] = {
		L"      \u001b[32m█████     ",
		L"   ███████████   ",
		L"  █████████████  ",
		L" ███████████████  ",
		L"█████████████████ ",
		L" ███████████████",
		L"  █████████████",
		L"       \u001b[2;33m███      ",
		L"       ███      ",
		L"       ███      ",
		L"       ███      ",
		L"       ███      ",
		L"       ███      "
	};

	// In cây thông
	for (int i = 0; i < 13; i++)
	{
		GotoXY(x, y + i);
		wcout << tree[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_RESET BACKGROUND_CYAN;
}

void EnderMan(int x, int y)
{
	cout << BACKGROUND_BLACK;
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring tree[13] = {
		L"        ",
		L"        ",
		L"\u001b[38;5;218m█\u001b[95m█\u001b[38;5;218m█  \u001b[38;5;218m█\u001b[95m█\u001b[38;5;218m█",
	    L"        ",
	};

	for (int i = 0; i < 13; i++)
	{
		GotoXY(x, y + i);
		wcout << tree[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	/*cout << COLOR_RESET BACKGROUND_CYAN*/;
}

void Chicken(int x, int y)
{
	cout << BACKGROUND_WHITE_SOFT;
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring tree[6] = {
		L"            ",
		L"  \u001b[30m ██  ██   ",
		L"  \u001b[33m ██████   ",
		L"  \u001b[33m\u001b[2m ██████   ",
		L"    \u001b[31m▐██▌    ",
		L"    \u001b[31m▐██▌    "
	};
	//▌▐
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << tree[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_RESET;
}




void MenuCloud1(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	// Tạo biến ông già Noel
	wstring logo[2] = {
	L"▁▂▃▄▅▆▇▇▆▅▄▃▂▃▄▆▇▇▆▅▄▇▆▅▄▃▁▂"
    };

	// In ông già Noel
	for (int i = 0; i < 2; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_WHITE COLOR_BOLD << logo[i] << " " ; 
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	cout << COLOR_RESET BACKGROUND_CYAN;
}

void MenuCloud2(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	// Tạo biến ông già Noel
	wstring logo[2] = {
	L"▁▂▃▄▆▇▇▆▅▄▇▆▅▄▃▁▂"
	};

	// In ông già Noel
	for (int i = 0; i < 2; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_WHITE COLOR_BOLD << logo[i] << " ";
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	cout << COLOR_RESET BACKGROUND_CYAN;
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


void CreeperMini(int x, int y) {
	cout << BACKGROUND_GREEN;
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[5];
	logo[0] = L"          ";
	logo[1] = L" \u001b[30m ██  ██  ";
	logo[2] = L"  \u001b[30m ▄██▄   ";
	logo[3] = L"  \u001b[30m █▀▀█   ";
	logo[4] = L"          ";

	for (int i = 0; i < 5; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	//cout << BACKGROUND_CYAN;

}

void DiamondPickaxe(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6];
	logo[0] = L"\u001b[34m  ▄█████▄▄\u001b[33m▄";
	logo[1] = L"\u001b[34m   ▀▀▀▀████";
	logo[2] = L"\u001b[33m     ▄██\u001b[34m▀███";
	logo[3] = L"\u001b[33m   ▄██▀  \u001b[34m███";
	logo[4] = L"\u001b[33m ▄██▀    \u001b[34m▀█▀";
	logo[5] = L"\u001b[33m██▀";

	//▄█▀▀



	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_BLACK;
}
void DiamondPickaxe2(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6];
	logo[0] = L"\u001b[33m ▄\u001b[96m▄▄█████▄";
	logo[1] = L"\u001b[96m ████▀▀▀▀";
	logo[2] = L"\u001b[96m███▀\u001b[33m██▄     ";
	logo[3] = L"\u001b[96m███  \u001b[33m▀██▄   ";
	logo[4] = L"\u001b[96m▀█▀    \u001b[33m▀██▄ ";
	logo[5] = L"         \u001b[33m▀██";

	//▄█▀▀



	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_BLACK;
}
void DiamondPickaxe3(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6];
	logo[0] = L"\u001b[96m  ▄█████▄▄\u001b[33m▄";
	logo[1] = L"\u001b[96m   ▀▀▀▀████";
	logo[2] = L"\u001b[33m     ▄██\u001b[96m▀███";
	logo[3] = L"\u001b[33m   ▄██▀  \u001b[96m███";
	logo[4] = L"\u001b[33m ▄██▀    \u001b[96m▀█▀";
	logo[5] = L"\u001b[33m██▀";

	//▄█▀▀



	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_BLACK;
}

void DiamondSword(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[8];
	logo[0] = L"\u001b[34m███▄      ";
	logo[1] = L"\u001b[34m▀████▄    ";
	logo[2] = L"\u001b[34m  ▀████▄      ";
	logo[3] = L"\u001b[34m    ▀████▄ ▄██ ";
	logo[4] = L"\u001b[34m      ▀██████ ";
	logo[5] = L"\u001b[34m       ▄██\u001b[33m██▄ ";
	logo[6] = L"\u001b[34m     ██▀▀ \u001b[33m▀██\u001b[34m▄ ";
	logo[7] = L"\u001b[34m            ▀▀ ";

	//▄█▀▀


	for (int i = 0; i < 8; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout <<  COLOR_BLACK;

}

void DiamondSword2(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[8];
	logo[0] = L"\u001b[96m███▄      ";
	logo[1] = L"\u001b[96m▀████▄    ";
	logo[2] = L"\u001b[96m  ▀████▄      ";
	logo[3] = L"\u001b[96m    ▀████▄ ▄██ ";
	logo[4] = L"\u001b[96m      ▀██████ ";
	logo[5] = L"\u001b[96m       ▄██\u001b[33m██▄ ";
	logo[6] = L"\u001b[96m     ██▀▀ \u001b[33m▀██\u001b[96m▄ ";
	logo[7] = L"\u001b[96m            ▀▀ ";

	//▄█▀▀


	for (int i = 0; i < 8; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_BLACK;

}
void DiamondSword3(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[8];
	logo[0] = L"\u001b[96m           ▄███";
	logo[1] = L"\u001b[96m         ▄████▀";
	logo[2] = L"\u001b[96m       ▄████▀";
	logo[3] = L"\u001b[96m ██▄ ▄████▀";
	logo[4] = L"\u001b[96m  ██████▀";
	logo[5] = L"\u001b[96m  \u001b[33m▄██\u001b[96m██▄";
	logo[6] = L"\u001b[96m ▄\u001b[33m██▀ \u001b[96m▀▀██";
	logo[7] = L"\u001b[96m ▀▀";

	//▄█▀▀


	for (int i = 0; i < 8; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout << COLOR_BLACK;

}

void RedMushroom(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[3];
	logo[0] = L"\u001b[31m ▄██▄";
	logo[1] = L"\u001b[31m██████";
	logo[2] = L"\u001b[93m  ██";

	//▄█▀▀


	for (int i = 0; i < 3; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	cout <<  COLOR_BLACK;


}


void GoldOre(int x, int y) {
	cout << BACKGROUND_BLACK;

	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[4];
	logo[0] = L"\u001b[33m ▄▄  ▄▄ ";
	logo[1] = L"\u001b[33m    ▀▀▀ ";
	logo[2] = L"\u001b[33m ▄▄  ▄  ";
	logo[3] = L"\u001b[33m ▀▀▀ ▀▀ ";

	//▄█▀▀

	for (int i = 0; i < 4; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);

	/*cout << COLOR_BLACK;*/
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
		wcout << COLOR_RED  << logo[i] << " " << COLOR_RESET BACKGROUND_CYAN;
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

void WinEffect(int x, int y, int Mode) {
	HideCursor();
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // Đổi chế độ ghi Unicode

	// Tạo biến logo chiến thắng
	wstring OWin[6] = {
		L" ██████╗    ██╗    ██╗██╗███╗   ██╗",
		L"██╔═══██╗   ██║    ██║██║████╗  ██║",
		L"██║   ██║   ██║ █╗ ██║██║██╔██╗ ██║",
		L"██║   ██║   ██║███╗██║██║██║╚██╗██║",
		L"╚██████╔╝   ╚███╔███╔╝██║██║ ╚████║",
		L" ╚═════╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝"
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
		L"██╗  ██╗",
		L"╚██╗██╔╝",
		L" ╚███╔╝",
		L" ██╔██╗",
		L"██╔╝╚██╗",
		L"╚═╝  ╚═╝"
	};

	for (int i = 0; i < 7; i++)
	{
		GotoXY(x, y + i);
		wcout << /*COLOR_RED <<*/ logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void OLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[7] = {
		L" █████╗",
		L"██╔══██╗",
		L"██║░░██║",
		L"██║░░██║",
		L"╚█████╔╝",
		L" ╚════╝"
	};

	for (int i = 0; i < 7; i++)
	{
		GotoXY(x, y + i);
		wcout << /*COLOR_BLUE <<*/ logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}


void BorderSquare(int xleft, int xright, int ytop, int ybottom, int speed)
{
	if (ytop == ybottom)
	{
		for (int i = xleft; i <= xright; i++) // để cho nó chạy từ 0
		{
			GotoXY(i, ytop); cout << char(220);
			Sleep(speed);
		}
	}
	else
	{
		for (int i = xleft; i <= xright; i++) // để cho nó chạy từ 0
		{
			GotoXY(i, ytop); cout << char(220); // 220
			GotoXY((xright - i) + xleft, ybottom); cout << char(223);//223
			Sleep(speed);
		}
		for (int i = (ytop + 1); i <= (ybottom - 1); i++) // để cho nó chạy từ 0
		{
			GotoXY(xleft, (ybottom - i) + ytop); cout << char(219);
			GotoXY(xright, i); cout << char(219);
			Sleep(speed);
		}
	}
}

void BorderSquareLine(int xleft, int xright, int ytop, int ybottom, int speed)
{
	if (ytop == ybottom)
	{
		for (int i = xleft; i <= xright; i++) // để cho nó chạy từ 0
		{
			GotoXY(i, ytop); cout << char(205);
			Sleep(speed);
		}
	}
	else
	{
		for (int i = xleft + 1; i <= (xright - 1); i++) // để cho nó chạy từ 0, ko in ngay góc
		{
			GotoXY(i, ytop); cout << char(205);
			GotoXY((xright - i) + xleft, ybottom); cout << char(205);
			Sleep(speed);
		}

		GotoXY(xright, ytop); cout << char(187);
		GotoXY(xleft, ybottom); cout << char(200);

		for (int i = (ytop + 1); i <= (ybottom - 1); i++) // để cho nó chạy từ 0
		{
			GotoXY(xleft, (ybottom - i) + ytop); cout << char(186);
			GotoXY(xright, i); cout << char(186);
			Sleep(speed);
		}

		GotoXY(xleft, ytop); cout << char(201);
		GotoXY(xright, ybottom); cout << char(188);
	}
}

void BorderSquareFILL(int xleft, int xright, int ytop, int ybottom)
{
	for (int i = ytop; i <= ybottom; i++)
	{
		for (int j = xleft; j <= xright; j++) // để cho nó chạy từ 0
		{
			GotoXY(j, i); cout << ' ';//char(219);
		}
	}
}

void SettingLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[7] = {
		L"░██████╗███████╗████████╗████████╗██╗███╗░░██╗░██████╗░",
		L"██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗░██║██╔════╝░",
		L"╚█████╗░█████╗░░░░░██║░░░░░░██║░░░██║██╔██╗██║██║░░██╗░",
		L"░╚═══██╗██╔══╝░░░░░██║░░░░░░██║░░░██║██║╚████║██║░░╚██╗",
		L"██████╔╝███████╗░░░██║░░░░░░██║░░░██║██║░╚███║╚██████╔╝",
		L"╚═════╝░╚══════╝░░░╚═╝░░░░░░╚═╝░░░╚═╝╚═╝░░╚══╝░╚═════╝░"
	};

	for (int i = 0; i < 7; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_BLUE << logo[i] << COLOR_RESET;
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void AboutLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[7] = {
		L"░█████╗░██████╗░░█████╗░██╗░░░██╗████████╗",
		L"██╔══██╗██╔══██╗██╔══██╗██║░░░██║╚══██╔══╝",
		L"███████║██████╦╝██║░░██║██║░░░██║░░░██║░░░",
		L"██╔══██║██╔══██╗██║░░██║██║░░░██║░░░██║░░░",
		L"██║░░██║██████╦╝╚█████╔╝╚██████╔╝░░░██║░░░",
		L"╚═╝░░╚═╝╚═════╝░░╚════╝░░╚═════╝░░░░╚═╝░░░"
	};

	for (int i = 0; i < 7; i++)
	{
		GotoXY(x, y + i);
		wcout <<COLOR_GREEN_HI << logo[i] << COLOR_RESET;
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void GuideLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[7] = {
		L"░██████╗░██╗░░░██╗██╗██████╗░███████╗",
		L"██╔════╝░██║░░░██║██║██╔══██╗██╔════╝",
		L"██║░░██╗░██║░░░██║██║██║░░██║█████╗░░",
		L"██║░░╚██╗██║░░░██║██║██║░░██║██╔══╝░░",
		L"╚██████╔╝╚██████╔╝██║██████╔╝███████╗",
		L"░╚═════╝░░╚═════╝░╚═╝╚═════╝░╚══════╝"
	};

	for (int i = 0; i < 7; i++)
	{
		GotoXY(x, y + i);
		wcout <<COLOR_YELLOW COLOR_DARK << logo[i] << COLOR_RESET;
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void PauseLogo(int x, int y)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[7] = {
		L"██████╗░░█████╗░██╗░░░██╗░██████╗███████╗",
		L"██╔══██╗██╔══██╗██║░░░██║██╔════╝██╔════╝",
		L"██████╔╝███████║██║░░░██║╚█████╗░█████╗░░",
		L"██╔═══╝░██╔══██║██║░░░██║░╚═══██╗██╔══╝░░",
		L"██║░░░░░██║░░██║╚██████╔╝██████╔╝███████╗",
		L"╚═╝░░░░░╚═╝░░╚═╝░╚═════╝░╚═════╝░╚══════╝"
	};
		
	for (int i = 0; i < 7; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void LoadLogo(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6] = {

	L"	██╗░░░░░░█████╗░░█████╗░██████╗░  ░██████╗░░█████╗░███╗░░░███╗███████╗",
	L"	██║░░░░░██╔══██╗██╔══██╗██╔══██╗  ██╔════╝░██╔══██╗████╗░████║██╔════╝",
	L"	██║░░░░░██║░░██║███████║██║░░██║  ██║░░██╗░███████║██╔████╔██║█████╗░░",
	L"	██║░░░░░██║░░██║██╔══██║██║░░██║  ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░",
	L"	███████╗╚█████╔╝██║░░██║██████╔╝  ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗",
	L"	╚══════╝░╚════╝░╚═╝░░╚═╝╚═════╝░  ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝"
	};

	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_CYAN COLOR_DARK << logo[i] << COLOR_RESET;
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}
void SaveNewFileLogo(int x, int y) {//vẽ cái khung trong đó nhập tên file
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring logo[6] = {

	L"	███╗░░██╗███████╗░██╗░░░░░░░██╗  ███████╗██╗██╗░░░░░███████╗  ███╗░░██╗░█████╗░███╗░░░███╗███████╗",
	L"	████╗░██║██╔════╝░██║░░██╗░░██║  ██╔════╝██║██║░░░░░██╔════╝  ████╗░██║██╔══██╗████╗░████║██╔════╝",
	L"	██╔██╗██║█████╗░░░╚██╗████╗██╔╝  █████╗░░██║██║░░░░░█████╗░░  ██╔██╗██║███████║██╔████╔██║█████╗░░",
	L"	██║╚████║██╔══╝░░░░████╔═████║░  ██╔══╝░░██║██║░░░░░██╔══╝░░  ██║╚████║██╔══██║██║╚██╔╝██║██╔══╝░░",
	L"	██║░╚███║███████╗░░╚██╔╝░╚██╔╝░  ██║░░░░░██║███████╗███████╗  ██║░╚███║██║░░██║██║░╚═╝░██║███████╗",
	L"	╚═╝░░╚══╝╚══════╝░░░╚═╝░░░╚═╝░░  ╚═╝░░░░░╚═╝╚══════╝╚══════╝  ╚═╝░░╚══╝╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝"
	};

	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void OfflineMode(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, lưu vào để hồi lại

	wstring logo[4] = {
		L"░█▀▀█ ░█─░█ ░█▀▀▀█ ░█▀▀▀█ ░█▀▀▀█ ░█▀▀▀ 　 ░█  ░█ ░█▀▀▀█ ░█ ░█ ░█▀▀█ 　 ░█▀▄▀█ ░█▀▀▀█ ░█▀▀▄ ░█▀▀▀",
		L"░█─── ░█▀▀█ ░█──░█ ░█──░█ ─▀▀▀▄▄ ░█▀▀▀ 　 ░█▄▄▄█ ░█──░█ ░█ ░█ ░█▄▄▀ 　 ░█░█░█ ░█──░█ ░█─░█ ░█▀▀▀",
		L"░█▄▄█ ░█─░█ ░█▄▄▄█ ░█▄▄▄█ ░█▄▄▄█ ░█▄▄▄ 　  ─░█ ─ ░█▄▄▄█  ▀▄▄▀ ░█─░█ 　 ░█──░█ ░█▄▄▄█ ░█▄▄▀ ░█▄▄▄"
	};

	for (int i = 0; i < 4; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

}
void PlayAgianLogo(int x, int y) {//vẽ cái khung của exit và play again
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);

	wstring Logo[6]{
		L"	██████╗░██╗░░░░░░█████╗░██╗░░░██╗  ░█████╗░░██████╗░░█████╗░██╗███╗░░██╗",
		L"	██╔══██╗██║░░░░░██╔══██╗╚██╗░██╔╝  ██╔══██╗██╔════╝░██╔══██╗██║████╗░██║",
		L"	██████╔╝██║░░░░░███████║░╚████╔╝░  ███████║██║░░██╗░███████║██║██╔██╗██║",
		L"	██╔═══╝░██║░░░░░██╔══██║░░╚██╔╝░░  ██╔══██║██║░░╚██╗██╔══██║██║██║╚████║",
		L"	██║░░░░░███████╗██║░░██║░░░██║░░░  ██║░░██║╚██████╔╝██║░░██║██║██║░╚███║",
		L"	╚═╝░░░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░  ╚═╝░░╚═╝░╚═════╝░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝"
	};
	for (int i = 0; i < 4; i++)
	{
		GotoXY(x, y + i);
		wcout << Logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

}
//Do you want to play again
void GameModeLogo(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring Logo[6]{

		L"	░██████╗░░█████╗░███╗░░░███╗███████╗  ███╗░░░███╗░█████╗░██████╗░███████╗",
		L"	██╔════╝░██╔══██╗████╗░████║██╔════╝  ████╗░████║██╔══██╗██╔══██╗██╔════╝",
		L"	██║░░██╗░███████║██╔████╔██║█████╗░░  ██╔████╔██║██║░░██║██║░░██║█████╗░░",
		L"	██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ██║╚██╔╝██║██║░░██║██║░░██║██╔══╝░░",
		L"	╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ██║░╚═╝░██║╚█████╔╝██████╔╝███████╗",
		L"	░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚══════╝"
	};

	for (int i = 0; i < 4; i++)
	{
		GotoXY(x, y + i);
		wcout << Logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

}
void SaveGameLogo(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring Logo[6]{

		L"	░██████╗░█████╗░██╗░░░██╗███████╗  ░██████╗░░█████╗░███╗░░░███╗███████╗",
		L"	██╔════╝██╔══██╗██║░░░██║██╔════╝  ██╔════╝░██╔══██╗████╗░████║██╔════╝",
		L"	╚█████╗░███████║╚██╗░██╔╝█████╗░░  ██║░░██╗░███████║██╔████╔██║█████╗░░",
		L"	░╚═══██╗██╔══██║░╚████╔╝░██╔══╝░░  ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░",
		L"	██████╔╝██║░░██║░░╚██╔╝░░███████╗  ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗",
		L"	╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝  ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝"
	};
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << Logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

}

void OverwriteLogo(int x, int y) {
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	wstring Logo[6]{

		L"	░█████╗░██╗░░░██╗███████╗██████╗░░██╗░░░░░░░██╗██████╗░██╗████████╗███████╗    ███████╗██╗██╗░░░░░███████╗",
		L"	██╔══██╗██║░░░██║██╔════╝██╔══██╗░██║░░██╗░░██║██╔══██╗██║╚══██╔══╝██╔════╝    ██╔════╝██║██║░░░░░██╔════╝",
		L"	██║░░██║╚██╗░██╔╝█████╗░░██████╔╝░╚██╗████╗██╔╝██████╔╝██║░░░██║░░░█████╗░░    █████╗░░██║██║░░░░░█████╗░░",
		L"	██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗░░████╔═████║░██╔══██╗██║░░░██║░░░██╔══╝░░    ██╔══╝░░██║██║░░░░░██╔══╝░░",
		L"	╚█████╔╝░░╚██╔╝░░███████╗██║░░██║░░╚██╔╝░╚██╔╝░██║░░██║██║░░░██║░░░███████╗    ██║░░░░░██║███████╗███████╗",
		L"	░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░╚═╝░░░╚══════╝    ╚═╝░░░░░╚═╝╚══════╝╚══════╝"
	};
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		wcout << COLOR_BLACK_HI << Logo[i];
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);

}
void backgroundGraphic()
{
	cout << BACKGROUND_CYAN;
	BorderSquareFILL(0, 119, 0, 27);
	
	cout << BACKGROUND_GREEN;
	BorderSquareFILL(0, 119, 28, 29);

}
