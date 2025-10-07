#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include "message.h"

#pragma comment(lib, "ws2_32.lib")  

using namespace std;

void  Client(const Message &msg) {
    // Starting the Winsock
    WSADATA wsaData;
    int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaResult != 0) {
        cerr << "WSAStartup Unsuccesfull: " << wsaResult << endl;
        return ;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        cerr << "Socket is not created: " << WSAGetLastError() << endl;
        WSACleanup();
        return ;
    }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        cerr << "Connection error: " << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        return ;
    }

    /*Message dataToSend = {
        "Hi,This my first socket program!",
        "Atakan",
        "Bektaş",
        22,
        1.82,
        true
    };*/

    vector<uint8_t> buffer = serialize(msg);

    int sent = send(sock, reinterpret_cast<const char*>(buffer.data()), buffer.size(), 0);
    if (sent == SOCKET_ERROR) {
        cerr << "Data could not send: " << WSAGetLastError() << endl;
    } else {
        cout << "Client: Mesage is sent. Size: " << sent << " bayt\n";
    }

    closesocket(sock);
    WSACleanup();
    
}
