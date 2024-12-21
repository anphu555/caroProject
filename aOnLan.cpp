#include <winsock2.h>
#include <iostream>
#include <string>
#include <thread>
#include "Functions.h"
#pragma comment(lib, "ws2_32.lib") // Link thư viện Winsock

#define PORT 12345
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
                cout << "- " << inet_ntoa(addr->sin_addr) << " (port 12345)" << endl;
            }

            freeaddrinfo(info);
        }
        else {
            cerr << "Failed to get IP addresses. Error: " << WSAGetLastError() << endl;
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

    // Chơi game
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
    int bytesReceived = recv(sock, buffer, sizeof(_POINT), 0);
    if (bytesReceived > 0) {
        deserializePoint(buffer, point);
    }
}

void LANcore(SOCKET sock, bool isHost) {
    while (true) {
        if (isHost) {
            moveWASDLAN();
            _POINT player1 = { _X, _Y, -1 };
            sendPoint(sock, player1);

            _POINT player2;
            recvPoint(sock, player2);
            moveArrowLAN();
        }
        else {
            _POINT player2;
            recvPoint(sock, player2);
            CheckBoard(_X, _Y, 0); //update board


            moveWASDLAN();
            _POINT player1 = { _X, _Y, -1 };
            sendPoint(sock, player1);
        }
    }
}


