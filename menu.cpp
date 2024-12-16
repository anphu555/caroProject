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

void About(){
    printf("\n======================== ABOUT ========================\n");
    printf("A small caro project developed by a bunch of randoms \n");
    printf("Developers: \n");
    printf("24127494: Vo An Phu\n");
    printf("24127074: Nguyen Le Duy Loc\n");
    printf("24127011: Nguyen Tuan An\n");
    printf("24127375: Nguyen Tai Hoan\n");
    printf("24127420: Pham Dinh Gia Khanh\n");
    printf("\n======================================================\n");
}

void Guide() {
    printf("\n======================== GUIDE ========================\n");
    //GotoXY(0, 0);//
    printf("Controls:\n");
    printf("  Player X (WASD):\n");
    printf("    W : Move up\n");
    printf("    A : Move left\n");
    printf("    D : Move right\n");
    printf("    S : Move down\n\n");
    printf("  Player O (Arrow Keys):\n");
    printf("    UP    : Move up\n");
    printf("    LEFT  : Move left\n");
    printf("    RIGHT : Move right\n");
    printf("    DOWN  : Move down\n\n");
    printf("Game Rules:\n");
    printf("  The goal of the game is to align 5 cells consecutively in\n");
    printf("  a straight line, diagonal, or horizontal line faster than\n");
    printf("  your opponent. Achieving 4 unblocked moves also wins.\n\n");
    printf("Tips:\n");
    printf("  - Plan ahead and block your opponent's moves.\n");
    printf("  - Use strategies from online resources to improve.\n");
    printf("=======================================================\n\n");
}

void Settings() { // mode 0 la luc moi vo game, 1 la luc pause, bool bool để tiết kiệm bộ nhớ
    // cais này sẽ chỉnh thành logo sau
    system("cls");
    HideCursor();
    cout << "=======Settings======\n\n";

    const int NUM_SETTINGS_ITEMS = 3;
    const char* settingsItems[NUM_SETTINGS_ITEMS] = {
        "Music: ON",
        "SFX: ON",
        "Back"
    };

    int selectedItem = 5;

    while (1) {

        system("cls");
        // Hiển thị menu cài đặt

        int toadoY1 = 15; // tọa đọ test vị trsi settings
        for (int i = 0; i < NUM_SETTINGS_ITEMS; i++) {
            GotoXY(10, toadoY1 + i * 2);

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
            if (selectedItem == 0) { // music mode

                if (settingsItems[selectedItem] == "Music: OFF")
                {
                    settingsItems[selectedItem] = "Music: ON";
                    backgroundMusicmode = true;
                    backgroundMusicSound();
                }
                else {
                    settingsItems[selectedItem] = "Music: OFF";
                    backgroundMusicmode = false;
                    backgroundMusicSound();
                }
            }
            else if (selectedItem == 1) { // sfx mode

                if (settingsItems[selectedItem] == "SFX: OFF")
                {
                    settingsItems[selectedItem] = "SFX: ON";
                    SFXmode = true;
                }
                else {
                    settingsItems[selectedItem] = "SFX: OFF";
                    SFXmode = false;
                }
            }
            else if (selectedItem == 2) { // exit
                return;     
            }

            break;
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
            /*CaroLogo(40, 1);*/
        IngameLogo4(10, 5);
        MenuLogo2(10, 14);

        system("color f0");
        // display menu with highlights

        // vị trí các ô chức năng
        int toadoY1 = 15;  // bien test ========================================== 
        
		for (int i = 0; i < NUM_MENU_ITEMS; i++) {
            GotoXY(((RIGHT + LEFT) / 2 ) - 15, toadoY1+i*2); // *2 thì giữa 2 chức năng có 1 khoảng cách

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
                switch (selectedItem) {
                    case 0: // New Game
                        system("cls");
                        StartGame();
                        GameMove();
                        return;
                    
                    case 1: // Load Game
                        system("cls");
                        loadGame();
                        GameMove();
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
                        break;
                    
                    case 4: // About
                        system("cls");
                        About();
                        cout << "Press any key to return to menu...";
                        getch();
                        break;
                   
                    case 5: // Exit
                        ExitGame();
                        exit(0);
                }
                break;
            
            case 27: 
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
                cout << ">> " << menuItems[i] << " <<" << endl;
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
                getch();
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
    int selectedFile = 0;

    while (true) {
        system("cls");
        cout << (isSaving ? "Select Save File:" : "Select Load File:") << endl;

        
       /* if (selectedFile == 0) {
            cout << ">> Back <<" << endl;
        }
        else {
            cout << "   Back" << endl;
        }*/

    
        if (isSaving) {
            if (selectedFile == 1) {
                cout << ">> New Save <<" << endl;
            }
            else {
                cout << "   New Save" << endl;
            }
        }

       
        for (int i = 0; i < saveFiles.size(); i++) {
            if (i + (isSaving ? 2 : 1) == selectedFile) {
                cout << ">> " << saveFiles[i] << " <<" << endl;
            }
            else {
                cout << "   " << saveFiles[i] << endl;
            }
        }

        if (selectedFile == 0) {
            cout << ">> Back <<" << endl;
        }
        else {
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

        case 13:
            if (selectedFile == 0) {
                return "BACK"; 
            }
            if (isSaving && selectedFile == 1) {
                // New Save
                system("cls");
                cout << "Enter save name: ";
                string filename;
                getline(cin, filename);
                if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".txt") {
                    filename += ".txt";
                }
                return filename;
            }
            return saveFiles[selectedFile - (isSaving ? 2 : 1)];
        }
    }
}




void saveGame() {
  
    if (_X == 0 && _Y == 0) {
        printf("Cannot save game before starting!\n");
        cout << "Press any key to continue...";
        getch();
        return;
    }

    const char* saveOptions[] = {
        "Save to New File",
        "Overwrite Existing Save"
    };
    int selectedOption = 0;

    while (true) {
        system("cls");
        cout << "Save Game Options:\n\n";

        // display menu with highlights
        for (int i = 0; i < 2; i++) {
            if (i == selectedOption) {
                cout << ">> " << saveOptions[i] << " <<\n";
            }
            else {
                cout << "   " << saveOptions[i] << "\n";
            }
        }

        int ch = getch();
        switch (ch) {
        case 'W':
        case 'w':
        case 72: // up arrow
            selectedOption = (selectedOption - 1 + 2) % 2;
            break;

        case 'S':
        case 's':
        case 80: // down arrow
            selectedOption = (selectedOption + 1) % 2;
            break;

        case 13: // enter
            if (selectedOption == 0) {
                AppearCursor();
                // save to new
                string filename = SelectSaveFile(true);
                if (filename == "BACK") return; // user canceled (Back)

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
            else {
               
                string filename = SelectSaveFile(false);
                if (filename == "BACK") return; // user canceled (Back)

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
            return;
        }
    }
}


void loadGame() {
    string filename = SelectSaveFile(false);
    if (filename == "BACK") {
        MenuHandler(); 
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
    else {
        printf("Error: Unable to open the file.\n");
        cout << "Press any key to continue...";
        getch();
        MenuHandler();
    }

    fclose(inFile);
}
