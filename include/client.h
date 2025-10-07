#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include <cstring>
#include "message.h"

#pragma comment(lib, "ws2_32.lib")  

void  Client(const Message &msg) {
    // Starting the Winsock
    WSADATA wsaData;
    int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaResult != 0) {
        std::cerr << "WSAStartup Unsuccesfull: " << wsaResult << std::endl;
        return ;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket is not created: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return ;
    }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        std::cerr << "Connection error: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return ;
    }

    

    std::vector<uint8_t> buffer = serialize(msg);

    int sent = send(sock, reinterpret_cast<const char*>(buffer.data()), static_cast<int>(buffer.size()), 0);
    if (sent == SOCKET_ERROR) {
        std::cerr << "Data could not send: " << WSAGetLastError() << std::endl;
    } else {
        std::cout << "Client: Mesage is sent. Size: " << sent << " bayt\n";
    }

    closesocket(sock);
    WSACleanup();
    
}
