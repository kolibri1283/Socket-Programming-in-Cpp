#include <iostream>
#include "include/message.h"
#include "include/client.h"
#include "include/server.h"
#include <chrono>
#include <thread>
/*#include <gtest/gtest.h>*/

int main() {
    
    Message msg = {
        "Hi,This is my first socket program!",
        "YourName",
        "YourSurname",
        22,
        1.82,
        true
    };
    
    std::thread serverThread(Server);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread clientThread(Client, msg);
    
    serverThread.join();
    clientThread.join();

    std::cout << "Server: Incoming informations\n";
    std::cout << "Message: " << msg.message << "\n";
    std::cout << "Name: " << msg.name << "\n";
    std::cout << "Surname: " << msg.surname << "\n";
    std::cout << "Age: " << msg.age << "\n";
    std::cout << "Height: " << msg.height << "\n";
    std::cout << "Is it active?: " << (msg.IsActive ? "Yes" : "No") << "\n";


    std::cout << "Process is succesfully done.\n";
    return 0;
}