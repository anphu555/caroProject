#include "Functions.h"
#pragma comment(lib, "ws2_32.lib") // Link thư viện Winsock

#define PORT 69696
#define BUFFER_SIZE 1024

using namespace std;

extern _POINT _A[3][BOARD_SIZE][BOARD_SIZE];
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;





// Hàm khởi tạo Winsock
void initWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Failed to initialize Winsock. Error: " << WSAGetLastError() << endl;
        exit(EXIT_FAILURE);
    }
}

// Hàm dọn dẹp Winsock
void cleanupWinsock() {
    WSACleanup();
}


// Server chính
void startServer() {
    SOCKET serverSocket, clientSocket;
    sockaddr_in serverAddr {}, clientAddr;
    int clientAddrSize = sizeof(clientAddr);

    // Tạo socket server
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Failed to create server socket. Error: " << WSAGetLastError() << endl;
        exit(EXIT_FAILURE);
    }

    // Thiết lập địa chỉ server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Bind failed. Error: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR) {
        cerr << "Failed to get hostname. Error: " << WSAGetLastError() << endl;
    }
    else {
        addrinfo hints = {}, * info;
        hints.ai_family = AF_INET; // IPv4
        hints.ai_socktype = SOCK_STREAM;

        if (getaddrinfo(hostname, nullptr, &hints, &info) == 0) {
            cout << "Server is running. Connect using one of these IPs:" << endl;

            for (addrinfo* ptr = info; ptr != nullptr; ptr = ptr->ai_next) {
                sockaddr_in* addr = reinterpret_cast<sockaddr_in*>(ptr->ai_addr);
                cout << "- " << inet_ntoa(addr->sin_addr) << " (port: " << PORT << ")" << endl;
            }

            freeaddrinfo(info);
        }
        else {
            cerr << "Failed to get IP address. Error: " << WSAGetLastError() << endl;
        }
    }

    // Lắng nghe kết nối
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed. Error: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    cout << "Waiting for a client to connect..." << endl;
    

    // Chấp nhận kết nối từ client

    clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Accept failed. Error: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        exit(EXIT_FAILURE);
    }

    cout << "Client connected!\n";

    // Initialize game first
    system("cls");
    StartGame();

    // Send initial game state
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _POINT boardState = { _A[0][i][j].x, _A[0][i][j].y, _A[0][i][j].c, false };
            sendPoint(clientSocket, boardState);
        }
    }
    // Chơi game
    LANcore(clientSocket, true);

    // Đóng socket
    closesocket(clientSocket);
    closesocket(serverSocket);
}

// Client chính
void startClient(const string& serverIP) {
    SOCKET clientSocket;
    sockaddr_in serverAddr;

    // Tạo socket client
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Failed to create client socket. Error: " << WSAGetLastError() << endl;
        exit(EXIT_FAILURE);
    }

    // Thiết lập địa chỉ server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());

    // Kết nối tới server
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Connection to server failed. Error: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        exit(EXIT_FAILURE);
    }

    cout << "Connected to server!\n";

    // Initialize empty game board
    system("cls");
    StartGame();

    // Receive initial game state
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _POINT boardState;
            recvPoint(clientSocket, boardState);
            _A[0][i][j] = { boardState.x, boardState.y, boardState.c };
        }
    }
    DrawBoard(); // Redraw board with received state

    LANcore(clientSocket, false);

    // Đóng socket
    closesocket(clientSocket);
}

//chuyen struct sang chuoi byte
void serializePoint(const _POINT& point, char* buffer) {
    memcpy(buffer, &point, sizeof(_POINT));
}


//giai chuoi byte thanh struct
void deserializePoint(const char* buffer, _POINT& point) {
    memcpy(&point, buffer, sizeof(_POINT));
}

//ham gui
void sendPoint(SOCKET sock, const _POINT& point) {
    char buffer[sizeof(_POINT)];
    serializePoint(point, buffer);
    send(sock, buffer, sizeof(_POINT), 0);
}



//ham nhan
void recvPoint(SOCKET sock, _POINT& point) {
    char buffer[sizeof(_POINT)];
    int totalReceived = 0;
    while (totalReceived < sizeof(_POINT)) {
        int bytesReceived = recv(sock, buffer + totalReceived, sizeof(_POINT) - totalReceived, 0);
        if (bytesReceived <= 0) {
            // Handle disconnect or error
            throw std::runtime_error("Connection lost");
        }
        totalReceived += bytesReceived;
    }
    deserializePoint(buffer, point);
}




void LANcore(SOCKET sock, bool isHost) {
    _TURN = true;  // Start with X's turn
    while (true) {
        DrawBoard();  // Refresh board each turn

        if (isHost) {  // Host plays X
            if (_TURN) {  // X's turn
                if (moveWASDLAN()) {
                    _POINT player1 = { _X, _Y, -1, true };
                    sendPoint(sock, player1);
                    _A[0][(_Y - TOP - 1) / 2][(_X - LEFT - 2) / 4].c = -1;
                    _TURN = false;
                    DrawBoard();
                }
            }
            else {  // O's turn
                _POINT player2;
                recvPoint(sock, player2);
                if (player2.isMove) {
                    _A[0][(player2.y - TOP - 1) / 2][(player2.x - LEFT - 2) / 4].c = 1;
                    _TURN = true;
                    DrawBoard();
                }
            }
        }
        else {  // Client plays O
            if (!_TURN) {  // O's turn
                if (moveArrowLAN()) {
                    _POINT player2 = { _X, _Y, 1, true };
                    sendPoint(sock, player2);
                    _A[0][(_Y - TOP - 1) / 2][(_X - LEFT - 2) / 4].c = 1;
                    _TURN = true;
                    DrawBoard();
                }
            }
            else {  // X's turn
                _POINT player1;
                recvPoint(sock, player1);
                if (player1.isMove) {
                    _A[0][(player1.y - TOP - 1) / 2][(player1.x - LEFT - 2) / 4].c = -1;
                    _TURN = false;
                    DrawBoard();
                }
            }
        }
    }
}
