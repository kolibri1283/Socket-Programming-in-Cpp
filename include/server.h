#include <iostream>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include "message.h"

#pragma comment(lib, "ws2_32.lib")  

void Server() {
    // Starting winsock
    WSADATA wsaData;
    int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaResult != 0) {
        std::cerr << "WSAStartup unsuccesfull: " << wsaResult <<std::endl;
        return ;
    }

    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_fd == INVALID_SOCKET) {
        std::cerr << "Socket did not created: " << WSAGetLastError() <<std::endl;
        WSACleanup();
        return ;
    }

    sockaddr_in server_addr{}, client_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (::bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Bind error: " << WSAGetLastError() <<std::endl;
        closesocket(server_fd);
        WSACleanup();
        return ;
    }

    if (listen(server_fd, 1) == SOCKET_ERROR) {
        std::cerr << "Listening error: " << WSAGetLastError() <<std::endl;
        closesocket(server_fd);
        WSACleanup();
        return ;
        
    }

    std::cout << "Server: Waiting for connection...\n";

    SOCKET client_fd;
    int client_len = sizeof(client_addr);
    client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);
    if (client_fd == INVALID_SOCKET) {
        std::cerr << "Accept error: " << WSAGetLastError() <<std::endl;
        closesocket(server_fd);
        WSACleanup();
        return ;
    }

    std::vector<uint8_t> buffer(sizeof(Message));
    int received = recv(client_fd, reinterpret_cast<char*>(buffer.data()), static_cast<int>(buffer.size()), 0);
    if (received <= 0) {
        std::cerr << "recv() is unsuccessfull !"<<std::endl;
        closesocket(client_fd);
        closesocket(server_fd);
        WSACleanup();
        return ;
    }

    if (received == buffer.size()) {
        std::cout << "Data is received. Size: " << buffer.size() <<std::endl;
    } else {
        std::cerr << "Data is lost! Expected: " << buffer.size()
             << ", Received: " << received <<std::endl;
    }

    Message receivedData = deserialize<Message>(buffer);

    std::cout << "Server: Data received from client."<<std::endl;
    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();
    
}
