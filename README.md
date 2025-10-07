🔌 SocketProgramming 
-This project demonstrates a simple TCP client-server communication setup using C++ and the Winsock2 API on Windows. -It showcases how to send and receive structured data over sockets using serialization and deserialization techniques. 
🚀Features 
-Server listens for incoming TCP connections and receives structured data. 
-Client connects to the server and sends a custom Message struct. Serialization and deserialization of data using raw memory operations. -Modular codebase with separate files for client, server, and shared message definitions. 
📁 Project Structure 
SocketProgramming/ 
├── client.cpp # Client-side logic 
├── server.cpp # Server-side logic 
├── message.h # Shared data structure and serialization helpers 
└── main.cpp # Entry point to run both client and server with threads