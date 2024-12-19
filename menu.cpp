#include "Functions.h"
#include "Color.h"
#include "graphic.h"
extern _POINT _A[3][BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;

extern bool backgroundMusicmode;
extern bool SFXmode; // false off, true on


void About() {
	AboutLogo(40, 2);

	GotoXY(30, 9);
	printf("A small caro project developed by a group of randoms chill boyz");


	BorderSquareLine(42, 72, 11, 15, 4);

	GotoXY(52, 12);
	printf(COLOR_ITALIC COLOR_BOLD COLOR_GREEN "Instructor:" COLOR_RESET);

	GotoXY(46, 14);
	printf("PhD. Truong Toan Thinh");


	BorderSquareLine(38, 77, 17, 25, 4);

	GotoXY(52, 18);
	printf(COLOR_ITALIC COLOR_BOLD COLOR_GREEN "Developers:" COLOR_RESET);

	GotoXY(44, 20);
	printf("24127011 - Nguyen Tuan An");

	GotoXY(44, 21);
	printf("24127074 - Nguyen Le Duy Loc");

	GotoXY(44, 22);
	printf("24127375 - Nguyen Tai Hoan");

	GotoXY(44, 23);
	printf("24127420 - Pham Dinh Gia Khanh");

	GotoXY(44, 24);
	printf("24127494 - Vo An Phu");

	GotoXY(44, 27);
}

void Guide() {
	GuideLogo(40, 2);

	BorderSquareLine(33, 85, 9, 15, 3);

	GotoXY(55, 10);
	printf(COLOR_ITALIC COLOR_BOLD COLOR_GREEN "Controls:" COLOR_RESET);

	// rut gon noi dung
	GotoXY(40, 12);
	printf(COLOR_UNDERLINE COLOR_RED COLOR_BOLD "Player X:" COLOR_RESET);

	GotoXY(40, 13);
	printf("W A S D");

	GotoXY(70, 12);
	printf(COLOR_UNDERLINE COLOR_BLUE COLOR_BOLD "Player O:" COLOR_RESET);

	GotoXY(70, 13);
	printf("Arrow keys");

	GotoXY(40, 14);
	printf("Enter");
	GotoXY(70, 14);
	printf("Enter");


	BorderSquareLine(27, 92, 17, 23, 3);

	GotoXY(55, 18);
	printf(COLOR_ITALIC COLOR_BOLD COLOR_GREEN "Game Rules:" COLOR_RESET);
	GotoXY(30, 20);
	printf("  The goal of the game is to align 5 cells consecutively in");
	GotoXY(30, 21);
	printf("  a straight line, diagonal, or horizontal line faster than");
	GotoXY(30, 22);
	printf("  your opponent. Achieving 4 unblocked moves also wins.");

	GotoXY(43, 27);
}

void Settings() { // mode 0 la luc moi vo game, 1 la luc pause, bool bool để tiết kiệm bộ nhớ
	// cais này sẽ chỉnh thành logo sau
	system("cls");
	HideCursor();


	SettingLogo(34, 3);
	BorderSquareLine(42, 78, 13, 21, 0);
	//SettingLogo(30, 3);
	//BorderSquareLine(42, 78, 13, 21, 0);

	const int NUM_SETTINGS_ITEMS = 3;
	const char* settingsItems[NUM_SETTINGS_ITEMS] = {
		"Music: ON",
		"SFX: ON",
		COLOR_RED_HI "Back" COLOR_RESET
	};

	int selectedItem = 5;

	while (1) {

		if (backgroundMusicmode) {   // music is on
			settingsItems[0] = "Music: \u001b[32m\u001b[1mON\u001b[0m\u001b[107m\u001b[30m";
		}
		else {
			settingsItems[0] = "Music: \u001b[1mOFF\u001b[0m\u001b[107m\u001b[30m";
		}

		if (SFXmode) {      //sfx is on
			settingsItems[1] = "SFX: \u001b[32m\u001b[1mON\u001b[0m\u001b[107m\u001b[30m";
		}
		else {
			settingsItems[1] = "SFX: \u001b[1mOFF\u001b[0m\u001b[107m\u001b[30m";
		}

		// Hiển thị menu cài đặt

		int toadoY1 = 15; // tọa đọ test vị trsi settings

		for (int i = 0; i < NUM_SETTINGS_ITEMS; i++) {
			GotoXY(((RIGHT + LEFT) / 2) - 7, 15 + i * 2);
			cout << "                        "; // Xóa dòng menu cũ
		}

		for (int i = 0; i < NUM_SETTINGS_ITEMS; i++) {

				GotoXY(((RIGHT + LEFT) / 2) - 7, toadoY1 + i * 2);
		
				GotoXY(((RIGHT + LEFT) / 2) - 7, 15 + i * 2);
			


				if (i == selectedItem) {
					cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
					cout << ">> " << settingsItems[i] << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK " <<";
					cout << COLOR_RESET;
				}
				else {
					cout << "   " << settingsItems[i];
				}
		}

		// lựa chọn các item
		char key = _getch();

		switch (key) {
		case UP_KEY:    case 'W':   case 'w':
			selectedItem = (selectedItem - 1 + NUM_SETTINGS_ITEMS) % NUM_SETTINGS_ITEMS;
			break;

		case DOWN_KEY:  case 'S':   case 's':
			selectedItem = (selectedItem + 1 + NUM_SETTINGS_ITEMS) % NUM_SETTINGS_ITEMS;
			break;

		case ENTER_KEY:
			switch (selectedItem)
			{
			case 0:
				backgroundMusicmode = !backgroundMusicmode; // doi mode
				backgroundMusicSound();
				break;
			case 1:
				SFXmode = !SFXmode; // doi mode
				pickSound();
				break;
			case 2: // exit
				pickSound();
				return;
			}

			break;
		case 27: // exit with esc
			pickSound();
			return;
		}
	}
}


bool sureExit() { // mode 0 la luc moi vo game, 1 la luc pause, bool bool để tiết kiệm bộ nhớ
	HideCursor();


	const int NUM_EXIT_ITEMS = 2;
	const char* exitItems[NUM_EXIT_ITEMS] = {
		COLOR_RED_HI "   YES   " /*COLOR_RESET*/,
		COLOR_BLUE_HI "   NO   " COLOR_RESET
	};

	int selectedItem = 3;

	while (1) {
		system("cls");

		BorderSquareLine(36, 73, 11, 18, 0);

		GotoXY(52, 12);
		printf(COLOR_ITALIC COLOR_BOLD COLOR_GREEN "EXIT" COLOR_RESET);

		GotoXY(40, 14);
		cout << "Are you sure you want to exit?";


		// hien thi menu;
		int toadoX1 = ((RIGHT + LEFT) / 2 - 7 - 10);


		for (int i = 0; i < NUM_EXIT_ITEMS; i++)
		{
			toadoX1 = toadoX1 + i * 14;
			GotoXY(toadoX1, 16); //*2 de moi dong cach 1 o
			if (selectedItem == 0)
			{
				exitItems[0] = ">> YES <<";
				exitItems[1] = COLOR_BLUE_HI "   NO   " COLOR_RESET ;
				cout << COLOR_RESET;
			}
			else if (selectedItem == 1)
			{
				exitItems[0] = COLOR_RED_HI "   YES   ";
				exitItems[1] = ">> NO <<";
				cout << COLOR_RESET;
			}

			if (i == selectedItem)
			{
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << exitItems[i];
				cout << COLOR_RESET;
			}
			else
			{
				cout << exitItems[i];
			}
		}

		// lua chon
		int choice = getch();
		switch (choice)
		{
		case 'A': case 'a': case 75:
			selectedItem = (selectedItem - 1 + NUM_EXIT_ITEMS) % NUM_EXIT_ITEMS;
			break;

		case 'D': case 'd': case 77:
			selectedItem = (selectedItem + 1) % NUM_EXIT_ITEMS;
			break;

		case 13: // enter
			pickSound();
			switch (selectedItem)
			{
			case 0:
				return true; // exit

				break;
			case 1:
				return false; // khong thoat
			}
			break;

		case 27: // back with esc
			pickSound();
			return false;
		}
	}
}




void MenuNewGame()
{
	const int NUM_NEWGAME_ITEMS = 3;
	const char* newgameItems[NUM_NEWGAME_ITEMS] = {
		"OFFLINE",
		" ONLAN ",
		 " \u001b[91mBACK\u001b[30m "
	};
	BorderSquareLine(48, 70, 12, 22, 0);
	OfflineMode(13, 5);
	int selectedItem = 5;

	while (1) {
		// hien thi menu
		system("cls");
		OfflineMode(13, 5); 
		BorderSquareLine(48, 70, 12, 22, 0);
		int toadoY1 = 15; // toa do kiemm thu
		for (int i = 0; i < NUM_NEWGAME_ITEMS; i++)
		{
			GotoXY(((RIGHT + LEFT) / 2 - 7), toadoY1 + i * 2); //*2 de moi dong cach 1 o
			if (i == selectedItem)
			{
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << newgameItems[i] << " <<";
				cout << COLOR_RESET;
			}
			else
			{
				cout << "   " << newgameItems[i];
			}
		}

		// lua chon
		int choice = getch();
		switch (choice)
		{
		case 'W': case 'w': case 72: //up
			selectedItem = (selectedItem - 1 + NUM_NEWGAME_ITEMS) % NUM_NEWGAME_ITEMS;
			break;

		case 'S': case 's': case 80: // down
			selectedItem = (selectedItem + 1) % NUM_NEWGAME_ITEMS;
			break;
		case 13: // enter
			pickSound();
			switch (selectedItem)
			{
			case 0:
				// che do offline
				MenuOffline();

				break;
			case 1:
				// che do online

				// am thanh ghep dau ==========

				break;
			case 2: //back
				return;
			}
			break;

		case 27: // back with esc
			pickSound();
			return;
		}
	}

}

void MenuOffline()
{
	const int NUM_OFFLINE_ITEMS = 3;
	const char* offlineItems[NUM_OFFLINE_ITEMS] = {
		"PvE",
		"PvP",
		"\u001b[91mBACK\u001b[30m"
	};

	system("cls");

	OfflineMode(13, 5);
	BorderSquareLine(48, 70, 12, 22, 0);
	int selectedItem = 5;

	while (1) {
		// hien thi menu
		system("cls");
		HideCursor();
		OfflineMode(13, 5);
		BorderSquareLine(48, 70, 12, 22, 0);
		int toadoY1 = 15; // toa do kiemm thu
		for (int i = 0; i < NUM_OFFLINE_ITEMS; i++)
		{
			GotoXY(((RIGHT + LEFT) / 2 - 6), toadoY1 + i * 2); //*2 de moi dong cach 1 o
			if (i == selectedItem)
			{
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << offlineItems[i] << " <<";
				cout << COLOR_RESET;
			}
			else
			{
				cout << "   " << offlineItems[i];
			}
		}

		// lua chon
		int choice = getch();
		switch (choice)
		{
		case 'W': case 'w': case 72: //up
			selectedItem = (selectedItem - 1 + NUM_OFFLINE_ITEMS) % NUM_OFFLINE_ITEMS;
			break;

		case 'S': case 's': case 80: // down
			selectedItem = (selectedItem + 1) % NUM_OFFLINE_ITEMS;
			break;
		case 13: // enter
			pickSound();
			switch (selectedItem)
			{
			case 0:
				// PvE
				newGameSound();

				system("cls");
				// Add a flag or global variable to indicate AI mode
				StartGame();
				// Modify moveWASD to handle AI play
				moveWASDAI();


				break;
			case 1:
				// PvP
				newGameSound();

				StartGame();
				GameMove();
				break;
			case 2: //back
				return;
			}
			break;

		case 27: // back with esc
			pickSound();
			return;
		}
	}

}


void MenuHandler() {
	const int NUM_MENU_ITEMS = 6;
	const char* menuItems[NUM_MENU_ITEMS] = {
		"  New Game",
		" Load Game",
		"  Settings",
		"   Guide  ",
		"   About  ",
		COLOR_RED_HI "   Exit   " 
	};

	//backgroundGraphic();

	int selectedItem = 11;
	while (true) {
		system("cls");

		system("color b0");

		//backgroundGraphic();
		cout << BACKGROUND_GREEN;
		BorderSquareFILL(0, 119, 28, 29);
		cout << BACKGROUND_CYAN;

		// BorderSquareLine(51, 73, 12, 16, 0);
		backgroundMusicSound();

		MenuLogo1(85, 14);
		IngameLogo4(13.5, 5);

		
		
		CreeperMini(10, 14);

		DiamondPickaxe(19, 13);

		//MenuLogo2(10, 14);
		
		//system("color f0");
		// display menu with highlights

		// vị trí các ô chức năng
		int toadoY1 = 15;  // bien test ========================================== 

		//for (int i = 0; i < NUM_MENU_ITEMS; i++) {
		//	GotoXY(((RIGHT + LEFT) / 2) - 6, toadoY1 + i * 2);
		//	cout << "                        "; // Xóa dòng menu cũ
		//}

		
		for (int i = 0; i < NUM_MENU_ITEMS; i++) {
			GotoXY(((RIGHT + LEFT) / 2) - 7, toadoY1 + i * 2); // *2 thì giữa 2 chức năng có 1 khoảng cách

			if (i == selectedItem) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << menuItems[i] << " <<";
				cout << COLOR_RESET BACKGROUND_CYAN;
			}
			else {
				cout << BACKGROUND_CYAN;
				cout << "   " << menuItems[i];
			}
		}

		// inpit
		int ch = getch();
		switch (ch) {
		case 'W': case 'w': case 72: // up
			selectedItem = (selectedItem - 1 + NUM_MENU_ITEMS) % NUM_MENU_ITEMS;
			break;

		case 'S': case 's': case 80: // down
			selectedItem = (selectedItem + 1) % NUM_MENU_ITEMS;
			break;

		case 13: // enter
			pickSound();

			system("color f0");

			switch (selectedItem) {
			case 0: // New Game
				system("cls");

				// offline pve pvp, onlline, back
				// offline pvp

				MenuNewGame();

				//StartGame();
				//GameMove();
				break;

			case 1: // Load Game
				system("cls");
				loadGame();
				//GameMove();
				break;

			case 2: // Settings
				system("cls");
				Settings();
				break;

			case 3: // Guide
				system("cls");
				Guide();
				cout << COLOR_RED_HI "Press any key to return to menu..." COLOR_RESET;
				HideCursor();
				getch();

				pickSound();

				break;

			case 4: // About
				system("cls");
				About();
				cout << COLOR_RED_HI "Press any key to return to menu..." COLOR_RESET;
				HideCursor();
				getch();

				pickSound();

				break;

			case 5: // Exit
				if (sureExit()) // true, exit
				{
					exitSound();

					ExitGame();
					exit(0);
					break;
				}
				// false, continue
				break;
			}
			break;

		case 27:
			if (sureExit()) // true, exit
			{
				exitSound();

				ExitGame();
				exit(0);
				break;
			}
			// false, continue
			break;
			exitSound();
		}
	}
}

void InGameMenu() {
	const int NUM_MENU_ITEMS = 5;
	const char* menuItems[NUM_MENU_ITEMS] = {
		"Continue",
		"Save Game",
		"Load Game",
		"Settings",
		COLOR_RED_HI "Exit Game"
	};

	int selectedItem = 9;

	system("cls");
	PauseLogo(40, 2);
	BorderSquareLine(47, 67, 12, 22, 0);

	while (true) {
		system("cls");
		HideCursor();
		PauseLogo(40, 2);

		BorderSquareLine(47, 67, 12, 22, 0);

		// display menu with highlights
		for (int i = 0; i < NUM_MENU_ITEMS; i++) {

			GotoXY(50, 13 + i * 2);

			if (i == selectedItem) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << menuItems[i] << " <<" << endl;
				cout << COLOR_RESET;
			}
			else {
				cout << "   " << menuItems[i] << endl;
				cout << COLOR_RESET;
			}
		}

		// input
		int ch = getch();
		switch (ch) {
		case 'W':
		case 'w':
		case 72: // up 
			selectedItem = (selectedItem - 1 + NUM_MENU_ITEMS) % NUM_MENU_ITEMS;
			break;

		case 'S':
		case 's':
		case 80: // down 
			selectedItem = (selectedItem + 1) % NUM_MENU_ITEMS;
			break;

		case 13: // enter
			pickSound();

			switch (selectedItem) {
			case 0: // Continue
				system("cls");
				AppearCursor();
				DrawBoard();
				// redraw existing X and O 
				for (int i = 0; i < BOARD_SIZE; i++) {
					for (int j = 0; j < BOARD_SIZE; j++) {
						GotoXY(_A[0][i][j].x, _A[0][i][j].y);
						if (_A[0][i][j].c == -1) {
							cout << COLOR_RED COLOR_BOLD << "X" << COLOR_RESET;
						}
						else if (_A[0][i][j].c == 1) {
							cout << COLOR_BLUE COLOR_BOLD << "O" << COLOR_RESET;
						}
					}
				}
				GotoXY(_X, _Y);
				return;

			case 1: // Save Game
				saveGame();
				/*getch();*/
				break;

			case 2: // Load Game
				system("cls");
				loadGame();

				break;

			case 3: // Settings
				Settings();
				break;

			case 4: // Exit Game
				if (sureExit()) // true, exit
				{
					ExitGame();
					MenuHandler(); // Quay lại menu chính
					return;
				}
				// false, continue
				break;
			}
			break;

		case 27:
			pickSound();

			system("cls");
			DrawBoard();

			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					GotoXY(_A[0][i][j].x, _A[0][i][j].y);
					if (_A[0][i][j].c == -1) {
						cout << COLOR_RED COLOR_BOLD << "X" << COLOR_RESET;
					}
					else if (_A[0][i][j].c == 1) {
						cout << COLOR_BLUE COLOR_BOLD << "O" << COLOR_RESET;
					}
				}
			}
			GotoXY(_X, _Y);
			return;
		}
	}
}


vector<string> GetSaveFiles() {
	vector<string> saveFiles;
	string savePath = ".";

	for (const auto& entry : directory_iterator(savePath)) {
		if (is_regular_file(entry)) {
			string filename = entry.path().filename().string();

			if (filename.length() > 4 && filename.substr(filename.length() - 4) == ".txt") {
				saveFiles.push_back(filename);
			}
		}
	}

	return saveFiles;
}

string SelectSaveFile(bool isSaving) {
	vector<string> saveFiles = GetSaveFiles();
	int selectedFile = 1;
	LoadLogo(22, 2);
	int borderTop = 13;
	int borderBottom = 27;
	int borderLeft = (RIGHT + LEFT) / 2 - 20;
	int borderRight = (RIGHT + LEFT) / 2 + 20;

	while (true) {
		system("cls");

		if (isSaving) {
			if (selectedFile == 1) {
				while (true) {
					system("cls");
					BorderSquareLine(34, 82, 18, 20, 0);
					SaveNewFileLogo(7.5, 11);
					GotoXY(48, 22);
					cout << "PRESS ESC TO GO BACK!";
					int borderX = 34, borderY = 18;
					GotoXY(borderX + 2, borderY + 1);
					string filename; 
					cout << "Enter save name: ";
					/*int cursorPos = 0;*/
					/*getline(cin, filename);*/
					int ch;
					
					/*bool escPressed = false;*/
					while (true) {
						
						ch = getch();
						if (ch == 27) { 
							/*escPressed = true;
							break;*/
							return "BACK";
						}
						else if (ch == '\r') { // Phím Enter

							break;
						}
						else if (ch == 8) { // Nhấn Backspace để xóa ký tự cuối
							if (!filename.empty()) {
								filename.pop_back(); // Xóa ký tự cuối trong chuỗi
								cout << "\b \b"; // Xóa ký tự trên màn hình
							}
						}
						else if (ch == -32 || ch == 224) { // Phím mũi tên (Windows)
							getch(); // Bỏ qua mã phím tiếp theo (phím điều hướng gửi mã kép)
						}
						else {
							filename += ch;
							cout << (char)ch; 
							 
						}
					}

				/*	if (escPressed) {
						return "BACK"; 
					}*/

					if (filename.empty()) {
						GotoXY(38,24 );
						cout << "File name cannot be empty! Please try again.\n";
						GotoXY(46, 25);
						cout << COLOR_RED_HI "Press any key to continue..." COLOR_RESET;
						getch();
						continue;
					}
					else if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".txt") {
						filename += ".txt"; 
						//GotoXY(38, 24);
					}
					return filename; 
				}
				continue; 
			}
		}
		else {

			system("cls");
			LoadLogo(22, 2);
			BorderSquareLine(borderLeft, borderRight, borderTop, borderBottom, 0);
			for (int i = 0; i < saveFiles.size(); i++) {
				int toadoY1 = 15;
				GotoXY(((RIGHT + LEFT) / 2) - 7, toadoY1 + i * 2);

				if (i + 1 == selectedFile) {
					cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
					cout << ">> " << saveFiles[i] << " <<" << endl;
					cout << COLOR_RESET;
				}
				else {
					cout << "   " << saveFiles[i] << endl;
				}
			}
		}

		if (selectedFile == 0) {
			int toadoY1 = 15;
			GotoXY(((RIGHT + LEFT) / 2) - 7, 25);
			cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
			cout << ">> Back <<" << endl;
			cout << COLOR_RESET;
		}
		else {
			int toadoY1 = 15;
			GotoXY(((RIGHT + LEFT) / 2) - 7, 25);
			cout << COLOR_RED_HI "   Back" << endl;
			cout << COLOR_RESET;
		}

		int ch = getch();
		switch (ch) {
		case 'W': case 'w': case 72: // Lên
			if (selectedFile > 0) {
				selectedFile--;
			}
			else { // Vòng về cuối danh sách
				selectedFile = isSaving ? 1 : saveFiles.size();
			}
			break;

		case 'S': case 's': case 80: // Xuống
			if (isSaving && selectedFile < 1) {
				selectedFile++;
			}
			else if (!isSaving && selectedFile < saveFiles.size()) {
				selectedFile++;
			}
			else { // Vòng về đầu danh sách
				selectedFile = 0;
			}
			break;

		case 13: // Enter
			pickSound();
			if (selectedFile == 0) { 
				return "BACK";
			}
			if (isSaving && selectedFile == 1) { 
				continue; 
			}
			return saveFiles[selectedFile - (isSaving ? 2 : 1)];

		case 27: // ESC
			pickSound();
			return "BACK";
		}
	}
}

void saveGame() {
	HideCursor();

	if (_X == 0 && _Y == 0) {
		printf("Cannot save game before starting!\n");
		cout << COLOR_RED_HI "Press any key to continue..." COLOR_RESET;
		HideCursor();
		getch();
		return;
	}

	const char* saveOptions[] = {
		"Save to New File",
		"Overwrite Existing Save",
		COLOR_RED_HI "Back"
	};
	int selectedOption = 0;

	while (true) {
		system("cls");
		SaveGameLogo(20, 2);
                BorderSquareLine(40, 77, 12, 22, 0);
		for (int i = 0; i < 3; i++) {
			int toadoY1 = 15;
			GotoXY(((RIGHT + LEFT) / 2) - 15, toadoY1 + i * 2);

			if (i == selectedOption) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << saveOptions[i] << " <<";
				cout << COLOR_RESET;
			}
			else {
				cout << "   " << saveOptions[i];
				cout << COLOR_RESET;
			}
		}

		int ch = getch();
		switch (ch) {
		case 'W': case 'w': case 72:
			selectedOption = (selectedOption - 1 + 3) % 3;
			break;

		case 'S': case 's': case 80:
			selectedOption = (selectedOption + 1) % 3;
			break;

		case 13:
			pickSound();
			if (selectedOption == 2) {
				return;
			}
			if (selectedOption == 0) {

				AppearCursor();
				string filename = SelectSaveFile(true); // Gọi hàm SelectSaveFile để chọn file mới
				if (filename == "BACK") {
					HideCursor();
					break;
				}
				FILE* outFile = fopen(filename.c_str(), "w");
				if (outFile) {
					// Save game state
					for (int i = 0; i < BOARD_SIZE; i++) {
						for (int j = 0; j < BOARD_SIZE; j++) {
							fprintf(outFile, "%d ", _A[0][i][j].c);
						}
						fprintf(outFile, "\n");
					}
					fprintf(outFile, "%d\n", _TURN);
					fprintf(outFile, "%d %d\n", _X, _Y);

					GotoXY(41, 24);

					printf("Game state saved to: %s\n", filename.c_str());
					fclose(outFile);

					saveSound();
					deleteOldestSaveFile(); // Xóa file cũ nếu có

					GotoXY(46, 25);
					cout << COLOR_RED_HI "Press any key to continue..." COLOR_RESET;
					HideCursor();
					getch();

					break;
				}
				else {
					HideCursor();
					GotoXY(41, 24);
					printf("Error: Unable to save the file.\n");

					GotoXY(46, 25);
					cout << COLOR_RED_HI "Press any key to continue..." COLOR_RESET;
					HideCursor();
					getch();
					break;
				}
			}
			if (selectedOption == 1) {

				AppearCursor();
				string filename = SelectSaveFile(false); // Chọn file đã tồn tại
				if (filename == "BACK") { // user canceled (Back)
					HideCursor();
					break;
				}
				FILE* outFile = fopen(filename.c_str(), "w"); // Mở file với chế độ ghi đè
				if (outFile) {
					// Save game state
					for (int i = 0; i < BOARD_SIZE; i++) {
						for (int j = 0; j < BOARD_SIZE; j++) {
							fprintf(outFile, "%d ", _A[0][i][j].c);
						}
						fprintf(outFile, "\n");
					}
					fprintf(outFile, "%d\n", _TURN);
					fprintf(outFile, "%d %d\n", _X, _Y);

					//=================
					GotoXY(43, 24);


					printf("Game state saved to: %s\n", filename.c_str());
					fclose(outFile);

					saveSound();
					deleteOldestSaveFile(); // Xóa file cũ nếu có

					GotoXY(46, 25);
					cout << COLOR_RED_HI "Press any key to continue..." COLOR_RESET;
					HideCursor();
					getch();
					break;
					//return;
				}
				else {
					printf("Error: Unable to save the file.\n");
					cout << COLOR_RED_HI "Press any key to continue..." COLOR_RESET;
					HideCursor();
					getch();
					return;
				}
			}
			break;

		case 27:
			pickSound();
			return;
		}
	}
}

void loadGame() {
	//LoadLogo(70, 30);
	HideCursor();

	string filename = SelectSaveFile(false);
	if (filename == "BACK") {
		// MenuHandler();
		return;
	}

	FILE* inFile = fopen(filename.c_str(), "r");
	if (inFile) {

		system("cls");
		ResetData();

		//đọc trạng thái bảng
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				fscanf(inFile, "%d", &_A[0][i][j].c);

				_A[0][i][j].x = 4 * j + LEFT + 2;
				_A[0][i][j].y = 2 * i + TOP + 1;
			}
		}

		//đọc lượt chơi
		int turn;
		fscanf(inFile, "%d", &turn);
		_TURN = turn;

		// đọc tọa độ 
		fscanf(inFile, "%d %d", &_X, &_Y);

		printf("Game state loaded from: %s\n", filename.c_str());
		fclose(inFile);

		// draw board
		DrawBoard();

		// draw X and O 
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				GotoXY(_A[0][i][j].x, _A[0][i][j].y);
				if (_A[0][i][j].c == -1) {
					cout << COLOR_RED COLOR_BOLD << "X" << COLOR_RESET;
				}
				else if (_A[0][i][j].c == 1) {
					cout << COLOR_BLUE COLOR_BOLD << "O" << COLOR_RESET;
				}
			}
		}

		GotoXY(_X, _Y);
		GameMove();
	}

	// ko can else vi phai nay co xoa duoc dau?

	//else {
	//	printf("Error: Unable to open the file.\n");
	//	cout << "Press any key to continue...";
	//	getch();
	//	MenuHandler();
	//}

	fclose(inFile);
}
namespace fs = experimental::filesystem;

// Hàm xóa file cũ nhất khi vượt quá giới hạn
void deleteOldestSaveFile() {
	vector<string> saveFiles;

	// Duyệt tất cả file .txt trong thư mục hiện tại
	for (const auto& entry : fs::directory_iterator(fs::current_path())) {
		if (entry.path().extension() == ".txt") {
			saveFiles.push_back(entry.path().string());
		}
	}

	// Kiểm tra nếu vượt quá 5 file
	if (saveFiles.size() > 5) {
		// Sắp xếp theo thời gian sửa đổi
		sort(saveFiles.begin(), saveFiles.end(), [](const string& a, const string& b) {
			return fs::last_write_time(a) < fs::last_write_time(b);
			});

		// Xóa file cũ nhất
		fs::remove(saveFiles.front());
	}
}

