#include "Functions.h"
#include "Color.h"
#include "graphic.h"
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;

extern bool backgroundMusicmode;
extern bool SFXmode; // false off, true on

// TAM THOI DE MAU TIM ===================================

void About() {
	/*printf("\n======================== ABOUT ========================\n");*/
	AboutLogo(40, 2);
	printf("\n");
	printf("				A small caro project developed by a group of randoms chill boyz \n");
	printf("Developers: \n");
	printf("24127494: Vo An Phu\n");
	printf("24127074: Nguyen Le Duy Loc\n");
	printf("24127011: Nguyen Tuan An\n");
	printf("24127375: Nguyen Tai Hoan\n");
	printf("24127420: Pham Dinh Gia Khanh\n");
	printf("\n======================================================\n");
}

void Guide() {
	GuideLogo(40, 1);

	BorderSquareLine(33, 85, 9, 15, 4);

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

	//printf("  Player X (WASD):\n");
	//printf("    W : Move up\n");
	//printf("    A : Move left\n");
	//printf("    D : Move right\n");
	//printf("    S : Move down\n\n");
	//printf("  Player O (Arrow Keys):\n");
	//printf("    UP    : Move up\n");
	//printf("    LEFT  : Move left\n");
	//printf("    RIGHT : Move right\n");
	//printf("    DOWN  : Move down\n\n");

	BorderSquareLine(27, 92, 17, 23, 5);

	GotoXY(55, 18);
	printf(COLOR_ITALIC COLOR_BOLD COLOR_GREEN "Game Rules:" COLOR_RESET);
	GotoXY(30, 20);
	printf("  The goal of the game is to align 5 cells consecutively in");
	GotoXY(30, 21);
	printf("  a straight line, diagonal, or horizontal line faster than");
	GotoXY(30, 22);
	printf("  your opponent. Achieving 4 unblocked moves also wins.");
	
	GotoXY(43, 27);
	//printf("Tips:\n");
	//printf("  - Plan ahead and block your opponent's moves.\n");
	//printf("  - Use strategies from online resources to improve.\n");
	//printf("=======================================================\n\n");
}

void Settings() { // mode 0 la luc moi vo game, 1 la luc pause, bool bool để tiết kiệm bộ nhớ
	// cais này sẽ chỉnh thành logo sau
	system("cls");
	HideCursor();
	
	/*cout << "=======Settings======\n\n";*/

	const int NUM_SETTINGS_ITEMS = 3;
	const char* settingsItems[NUM_SETTINGS_ITEMS] = {
		"Music: ON",
		"SFX: ON",
		"Back"
	};

	int selectedItem = 5;

	while (1) {

		system("cls");
		SettingLogo(30, 8);
		if (backgroundMusicmode) {   // music is on
			settingsItems[0] = "Music: ON";
		}
		else {
			settingsItems[0] = "Music: OFF";
		}

		if (SFXmode) {      //sfx is on
			settingsItems[1] = "SFX: ON";
		}
		else {
			settingsItems[1] = "SFX: OFF";
		}

		// Hiển thị menu cài đặt

		int toadoY1 = 15; // tọa đọ test vị trsi settings

		for (int i = 0; i < NUM_SETTINGS_ITEMS; i++) {
			GotoXY(((RIGHT + LEFT) / 2) - 15, toadoY1 + i * 2);


			if (i == selectedItem) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << settingsItems[i] << " <<";
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

void MenuNewGame()
{
	const int NUM_NEWGAME_ITEMS = 3;
	const char* newgameItems[NUM_NEWGAME_ITEMS] = {
		"OFFLINE",
		"ONLINE",
		"BACK"
	};

	int selectedItem = 5;

	while (1) {
		// hien thi menu
		system("cls");

		int toadoY1 = 15; // toa do kiemm thu
		for (int i = 0; i < NUM_NEWGAME_ITEMS; i++)
		{
			GotoXY(((RIGHT + LEFT) / 2 - 15), toadoY1 + i*2); //*2 de moi dong cach 1 o
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
		"BACK"
	};

	int selectedItem = 5;

	while (1) {
		// hien thi menu
		system("cls");

		int toadoY1 = 15; // toa do kiemm thu
		for (int i = 0; i < NUM_OFFLINE_ITEMS; i++)
		{
			GotoXY(((RIGHT + LEFT) / 2 - 15), toadoY1 + i * 2); //*2 de moi dong cach 1 o
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

				// ham che do pve ======================================================


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
		"   Exit   "
	};

	int selectedItem = 11;
	while (true) {
		system("cls");

		backgroundMusicSound();

		MenuLogo1(70, 14);
		IngameLogo4(10, 5);
		MenuLogo2(10, 14);

		//system("color f0");
		// display menu with highlights

		// vị trí các ô chức năng
		int toadoY1 = 15;  // bien test ========================================== 

		for (int i = 0; i < NUM_MENU_ITEMS; i++) {
			GotoXY(((RIGHT + LEFT) / 2) - 15, toadoY1 + i * 2); // *2 thì giữa 2 chức năng có 1 khoảng cách

			if (i == selectedItem) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << menuItems[i] << " <<";
				cout << COLOR_RESET;
			}
			else {
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
				cout << "Press any key to return to menu...";
				getch();

				pickSound();

				break;

			case 4: // About
				system("cls");
				About();
				cout << "Press any key to return to menu...";
				getch();

				pickSound();

				break;

			case 5: // Exit
				exitSound();

				ExitGame();
				exit(0);
			}
			break;

		case 27:
			exitSound();

			ExitGame();
			exit(0);
			break;
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
		"Exit Game"
	};

	int selectedItem = 9;

	while (true) {
		system("cls");
		HideCursor();
		cout << "====================== PAUSING ======================" << "\n" << "\n";

		// display menu with highlights
		for (int i = 0; i < NUM_MENU_ITEMS; i++) {
			if (i == selectedItem) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << menuItems[i] << " <<" << endl;
				cout << COLOR_RESET;
			}
			else {
				cout << "   " << menuItems[i] << endl;
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
						GotoXY(_A[i][j].x, _A[i][j].y);
						if (_A[i][j].c == -1) {
							cout << COLOR_RED COLOR_BOLD << "X" << COLOR_RESET;
						}
						else if (_A[i][j].c == 1) {
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
				ExitGame();
				MenuHandler(); // Quay lại menu chính
				return;
			}
			break;

		case 27:
			pickSound();

			system("cls");
			DrawBoard();

			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					GotoXY(_A[i][j].x, _A[i][j].y);
					if (_A[i][j].c == -1) {
						cout << COLOR_RED COLOR_BOLD << "X" << COLOR_RESET;
					}
					else if (_A[i][j].c == 1) {
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
	int selectedFile = 6;

	while (true) {
		system("cls");
		cout << (isSaving ? "Select Save File:" : "Select Load File:") << endl;


		/* if (selectedFile == 0) {
			 cout << ">> Back <<" << endl;
		 }
		 else {
			 cout << "   Back" << endl;
		 }*/


		// đây là lúc lưu file

		if (isSaving) {

			if (selectedFile == 1) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> New Save <<" << endl;
				cout << COLOR_RESET;
			}
			else {
				cout << "   New Save" << endl;
			}
		}


		for (int i = 0; i < saveFiles.size(); i++) {

			int toadoY1 = 15; // toa độ kiểm thử
			GotoXY(((RIGHT + LEFT) / 2) - 15, toadoY1 + i * 2); // *2 thì giữa 2 chức năng có 1 khoảng cách


			if (i + (isSaving ? 2 : 1) == selectedFile) {
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << saveFiles[i] << " <<" << endl;
				cout << COLOR_RESET;

			}
			else {
				cout << "   " << saveFiles[i] << endl;
			}
		}

		if (selectedFile == 0) {


			int toadoY1 = 15; // toa độ kiểm thử
			GotoXY(((RIGHT + LEFT) / 2) - 15, 25); 


			cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
			cout << ">> Back <<" << endl;
			cout << COLOR_RESET;
		}
		else {

			int toadoY1 = 15; // toa độ kiểm thử
			GotoXY(((RIGHT + LEFT) / 2) - 15, 25);


			cout << "   Back" << endl;
		}

		int ch = getch();
		switch (ch) {
		case 'W': case 'w': case 72:
			selectedFile = (selectedFile - 1 + saveFiles.size() + (isSaving ? 2 : 1))
				% (saveFiles.size() + (isSaving ? 2 : 1));
			break;

		case 'S': case 's': case 80:
			selectedFile = (selectedFile + 1)
				% (saveFiles.size() + (isSaving ? 2 : 1));
			break;

		case 13: // enter
			pickSound();

			if (selectedFile == 0) {
				return "BACK";
			}
			if (isSaving && selectedFile == 1) {
				// New Save
				system("cls");
				cout << "Enter save name: ";
				string filename;
				getline(cin, filename);
				
				if (filename.empty()) {
					cout << "File name cannot be empty! Please try again.\n";
					cout << "Press any key to continue...";
					getch();
					break;
				}
				else if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".txt") {
					filename += ".txt";
				}
		
				return filename;
			}
			return saveFiles[selectedFile - (isSaving ? 2 : 1)];

		case 27: // exit with esc
			pickSound();

			return "BACK";
		}
	}
}



void saveGame() {
	HideCursor();

	if (_X == 0 && _Y == 0) {
		printf("Cannot save game before starting!\n");
		cout << "Press any key to continue...";
		getch();
		return;
	}

	const char* saveOptions[] = {
		"Save to New File",
		"Overwrite Existing Save",
		"Back"
	};
	int selectedOption = 5;

	while (true) {
		system("cls");
		cout << "Save Game Options:\n\n";

		// display menu with highlights
		for (int i = 0; i < 3; i++) {

			int toadoY1 = 15; // toa độ kiểm thử
			GotoXY(((RIGHT + LEFT) / 2) - 15, toadoY1 + i * 2); // *2 thì giữa 2 chức năng có 1 khoảng cách

			if (i == selectedOption) {

				//==================================
				cout << BACKGROUND_YELLOW COLOR_WHITE COLOR_BOLD COLOR_DARK;
				cout << ">> " << saveOptions[i] << " <<";
				cout << COLOR_RESET;
				
			}
			else {
				cout << "   " << saveOptions[i];
			}
		}

		int ch = getch();
		switch (ch) {
		case 'W':
		case 'w':
		case 72: // up arrow
			selectedOption = (selectedOption - 1 + 3) % 3;
			break;

		case 'S':
		case 's':
		case 80: // down arrow
			selectedOption = (selectedOption + 1) % 3;
			break;

		case 13: // enter
			pickSound();
			if (selectedOption == 2) {
				return;
			}
			if (selectedOption == 0) {
				AppearCursor();
				// save to new
				string filename = SelectSaveFile(true);
				if (filename == "BACK")		break; // user canceled (Back) , break de nhay khoi switch ko phai return

				FILE* outFile = fopen(filename.c_str(), "w");
				if (outFile) {
					// lưu trạng thái của bảng!!!
					for (int i = 0; i < BOARD_SIZE; i++) {
						for (int j = 0; j < BOARD_SIZE; j++) {
							fprintf(outFile, "%d ", _A[i][j].c);
						}
						fprintf(outFile, "\n");
					}
					// save lượt chơi
					fprintf(outFile, "%d\n", _TURN);
					// save tọa độ
					fprintf(outFile, "%d %d\n", _X, _Y);

					printf("Game state saved to: %s\n", filename.c_str());
					fclose(outFile);

					// am thanh save file tahnh cong
					saveSound();
					deleteOldestSaveFile();
					cout << "Press any key to continue...";
					getch();

					fclose(outFile);

					return;
				}
			/*	else if (filename.length() == 0 && filename.substr(filename.length() - 4) != ".txt") {
					cout << "Invalid file name!" << endl;
					cout << "Press any key to continue...";
					getch();
				}*/
				else {
					printf("Error: Unable to save the file.\n");
					cout << "Press any key to continue...";
					getch();
					return;
				}
			}
			else {

				string filename = SelectSaveFile(false);
				if (filename == "BACK") break; // user canceled (Back)

				FILE* outFile = fopen(filename.c_str(), "w");
				if (outFile) {
					// lưu trạng thái của bảng!!!
					for (int i = 0; i < BOARD_SIZE; i++) {
						for (int j = 0; j < BOARD_SIZE; j++) {
							fprintf(outFile, "%d ", _A[i][j].c);
						}
						fprintf(outFile, "\n");
					}
					// save lượt chơi
					fprintf(outFile, "%d\n", _TURN);
					// save tọa độ
					fprintf(outFile, "%d %d\n", _X, _Y);

					printf("Game state saved to: %s\n", filename.c_str());
					/*fclose(outFile);*/


					// am thanh save file tahnh cong
					saveSound();
					deleteOldestSaveFile();


					cout << "Press any key to continue...";
					getch();

					fclose(outFile);

					


					return;
				}
				else {
					printf("Error: Unable to save the file.\n");
					cout << "Press any key to continue...";
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
				fscanf(inFile, "%d", &_A[i][j].c);

				_A[i][j].x = 4 * j + LEFT + 2;
				_A[i][j].y = 2 * i + TOP + 1;
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
				GotoXY(_A[i][j].x, _A[i][j].y);
				if (_A[i][j].c == -1) {
					cout << COLOR_RED COLOR_BOLD << "X" << COLOR_RESET;
				}
				else if (_A[i][j].c == 1) {
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
