# 🔌 SocketProgramming 

This project demonstrates a simple TCP client-server communication setup using C++ and the Winsock2 API on Windows. It showcases how to send and receive structured data over sockets using serialization and deserialization techniques.

## 🚀 Features 

- Server listens for incoming TCP connections and receives structured data
- Client connects to the server and sends a custom Message struct
- Serialization and deserialization of data using raw memory operations
- Modular codebase with separate files for client, server, and shared message definitions

## 📁 Project Structure 

```
SocketProgramming/
├── client.cpp    # Client-side logic
├── server.cpp    # Server-side logic
├── message.h     # Shared data structure and serialization helpers
└── main.cpp      # Entry point to run both client and server with threads
```

## 🛠️ Process Structure

### Server Process Flow:
1. **Initialize Winsock2** - Setup Windows Socket library
2. **Create Socket** - Create TCP socket for server
3. **Bind Socket** - Bind socket to IP address and port
4. **Listen for Connections** - Put socket in listening mode
5. **Accept Connections** - Accept incoming client connections
6. **Receive Data** - Receive serialized message from client
7. **Deserialize** - Convert raw data back to Message struct
8. **Process Message** - Handle the received message
9. **Send Response** - Send acknowledgment back to client
10. **Cleanup** - Close sockets and cleanup resources

### Client Process Flow:
1. **Initialize Winsock2** - Setup Windows Socket library
2. **Create Socket** - Create TCP socket for client
3. **Connect to Server** - Establish connection to server
4. **Create Message** - Prepare Message struct with data
5. **Serialize Data** - Convert Message struct to raw bytes
6. **Send Data** - Transmit serialized data to server
7. **Receive Response** - Wait for server acknowledgment
8. **Cleanup** - Close socket and cleanup resources

### Threading Model:
- **Main Thread**: Launches both client and server in separate threads
- **Server Thread**: Handles incoming connections and data processing
- **Client Thread**: Manages connection establishment and data transmission
