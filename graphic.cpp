#include "graphic.h"
#include "Functions.h"
#include "Color.h"

void CaroLogo(int x, int y)
{
    int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, luu vô để hồi đổi lại
	// tạo biến logo caro
    wstring logo[9];
	logo[0] = L" ▄▄██▀▀▀  ▄█████▄   ▄█████▄    ▄██████▄ ";
	logo[1] = L"▄██▀          ▀███  ██▀  ▀██  ██▀    ▀██";
	logo[2] = L"██              ██  ██   ▄██  ██      ██";
	logo[3] = L"██        ▄████▄██  ██▄███▀   ██  ██  ██";
	logo[4] = L"██       ██▀   ▀██  ██▀█▄     ██      ██";
	logo[5] = L"▀██▄     ██▄   ▄██  ██ ▀██▄   ██▄    ▄██";
	logo[6] = L" ▀▀██▄▄▄ ▀█████▀▀   ██   ▀██▄▄ ▀██████▀ ";
    logo[7] = L"               ▄   ▄██                  ";
    logo[8] = L"               ▀████▀                   ";

	// in logo caro
	for (int i = 0; i < 9; i++)
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
	wstring logo[12];
			
	logo[0] =  L"⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣄⡀                ";
	logo[1] =  L"⠀⠀⠀⠀⢀⣿⠇⠀⢀⣴⣶⡾⠿⠿⠿⢿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	logo[2] =  L"⠀⠀⣀⣀⣸⡿⠀⠀⢸⣿⣇⠀⠀⠀⠀⠀⠀⠙⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	logo[3] =  L"⠀⣾⡟⠛⣿⡇⠀⠀⢸⣿⣿⣷⣤⣤⣤⣤⣶⣶⣿⠇⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀";
	logo[4] =  L"⢀⣿⠀⢀⣿⡇⠀⠀⠀⠻⢿⣿⣿⣿⣿⣿⠿⣿⡏⠀⠀⠀⠀⢴⣶⣶⣿⣿⣿⣆";
	logo[5] =  L"⢸⣿⠀⢸⣿⡇⠀⠀⠀⠀⠀⠈⠉⠁⠀⠀⠀⣿⡇⣀⣠⣴⣾⣮⣝⠿⠿⠿⣻⡟";
	logo[6] =  L"⢸⣿⠀⠘⣿⡇⠀⠀⠀⠀⠀⠀⠀⣠⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠉⠀";
	logo[7] =  L"⠸⣿⠀⠀⣿⡇⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠉⠀⠀⠀⠀";
	logo[8] =  L"⠀⠻⣷⣶⣿⣇⠀⠀⠀⢠⣼⣿⣿⣿⣿⣿⣿⣿⣛⣛⣻⠉⠁⠀⠀⠀⠀⠀⠀⠀";
	logo[9] =  L"⠀⠀⠀⠀⢸⣿⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀";
	logo[10] = L"⠀⠀⠀⠀⢸⣿⣀⣀⣀⣼⡿⢿⣿⣿⣿⣿⣿⡿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀ ";
	logo[11] = L"⠀⠀⠀⠀⠀⠙⠛⠛⠛⠋⠁⠀⠙⠻⠿⠟⠋⠑⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀ ";

	// in logo caro
	for (int i = 0; i < 12; i++)
	{
		GotoXY(x, y + i);
		wcout << logo[i];
	}
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}

void WinEffect(int x, int y, int Mode)
{
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT); // _setmode return mode trước khi bị đổi, luu vô để hồi đổi lại
	// tạo biến logo chiến thắng
	// mode -1: o win
	wstring OWin[6];
	OWin[0] = L" ██████╗     ██╗    ██╗██╗███╗   ██╗";
	OWin[1] = L"██╔═══██╗    ██║    ██║██║████╗  ██║";
	OWin[2] = L"██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║";
	OWin[3] = L"██║   ██║    ██║███╗██║██║██║╚██╗██║";
	OWin[4] = L"╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║";
	OWin[5] = L" ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	// mode 1: x win
	wstring XWin[6];
	XWin[0] = L"██╗  ██╗     ██╗    ██╗██╗███╗   ██╗";
	XWin[1] = L"╚██╗██╔╝     ██║    ██║██║████╗  ██║";
	XWin[2] = L" ╚███╔╝      ██║ █╗ ██║██║██╔██╗ ██║";
	XWin[3] = L" ██╔██╗      ██║███╗██║██║██║╚██╗██║";
	XWin[4] = L"██╔╝ ██╗     ╚███╔███╔╝██║██║ ╚████║";
	XWin[5] = L"╚═╝  ╚═╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝";

	// mode 0: draw
	wstring Draw[6];
	Draw[0] = L"██████╗ ██████╗  █████╗ ██╗    ██╗";
	Draw[1] = L"██╔══██╗██╔══██╗██╔══██╗██║    ██║";
	Draw[2] = L"██║  ██║██████╔╝███████║██║ █╗ ██║";
	Draw[3] = L"██║  ██║██╔══██╗██╔══██║██║███╗██║";
	Draw[4] = L"██████╔╝██║  ██║██║  ██║╚███╔███╔╝";
	Draw[5] = L"╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝ ";

	// in logo caro
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y + i);
		switch (Mode)
		{
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
	winSound();
	int CurrentMode = _setmode(_fileno(stdout), OldMode);
}