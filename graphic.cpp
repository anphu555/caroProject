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
	logo[6] = L" ▀▀██▄▄▄ ▀█████▀▀   ██   ▀██▄  ▀██████▀ ";
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