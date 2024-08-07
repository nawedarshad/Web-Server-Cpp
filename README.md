# Web-Server-CPP

Sure! Here's a `README.md` file for your project:

```markdown
# Simple HTTP Server

This is a simple HTTP server implemented in C++ using Winsock. The server listens on `127.0.0.1:8080` and responds with a basic "Hello World" HTML page to any incoming HTTP requests.

## How It Works

1. The server initializes the Winsock library.
2. It creates a TCP socket and binds it to the local loopback address `127.0.0.1` on port `8080`.
3. The server listens for incoming connections with a backlog of 20 connections.
4. When a client connects, the server accepts the connection and receives the client's request.
5. The server constructs a simple HTTP response with a "Hello World" HTML page and sends it back to the client.
6. The server closes the connection with the client and waits for new connections.

## How to Run

### Prerequisites

- Windows operating system
- C++ compiler (g++ with MinGW recommended)
- Winsock library

### Steps

1. **Clone the repository** (if the code is in a repository) or **copy the code** into a file named `main.cpp`.

2. **Open a terminal or command prompt** and navigate to the directory containing `main.cpp`.

3. **Compile the code** using `g++` with the Winsock library:

   ```bash
   g++ main.cpp -o server.exe -lWs2_32
   ```

4. **Run the compiled executable**:

   ```bash
   ./server.exe
   ```

5. **Open a web browser** and navigate to `http://127.0.0.1:8080`. You should see a "Hello World" message.

## Code Explanation

### Includes and Namespace

```cpp
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include<iostream>
#include<windows.h>
#include<winsock2.h>
#include<string>
using namespace std;
```

- Suppresses deprecated Winsock function warnings.
- Links the Winsock library.
- Includes necessary headers for I/O operations, Windows API, Winsock, and strings.
- Uses the standard namespace.

### Main Function

```cpp
int main(int argc, char const *argv[])
{
    return 0;
}
```

- Initializes Winsock.
- Creates and binds a TCP socket.
- Listens for incoming connections.
- Accepts connections and handles client requests.
- Sends an HTTP response with a "Hello World" message.
- Closes the client and server sockets.

## Error Handling

- The server prints error messages to the console if it fails to initialize Winsock, create or bind the socket, start listening, accept connections, or read client requests.
