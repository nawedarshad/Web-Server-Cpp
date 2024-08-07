#define _WINSHOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include<iostream>
#include<windows.h>
#include<winsock2.h>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"Attempting to connect\n";
    SOCKET wsocket;
    SOCKET new_wsocket;
    WSADATA wsadata;
    struct sockaddr_in server;
    int server_len;
    int BUFFER = 37020;

    if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0){
        cout<<"Could Not initialize\n";
    }

    wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (wsocket == INVALID_SOCKET){
        cout<<"Could not create Socket\n";
    }
    
     server.sin_family = AF_INET;
     server.sin_addr.s_addr = inet_addr("127.0.0.1");
     server.sin_port = htons(8080);
     server_len = sizeof(server);

     if (bind(wsocket, (SOCKADDR *)&server, server_len) != 0){
        cout<<"Could not Bind Socket\n";
     }
     
     if (listen(wsocket, 20) != 0){
        cout<<"Could not start Listening\n";
     }
     cout<<"Listening on 127.0.0.1:8080\n";
     int bytes = 0;
     while (true){
        new_wsocket = accept(wsocket, (SOCKADDR *)&server, &server_len);
        if (new_wsocket == INVALID_SOCKET){
            cout<<"Could not handle Accept\n";
        }
        
        char buff[30720] = {0};
        bytes = recv(new_wsocket, buff, BUFFER, 0);
        if (bytes<0){
            cout<<"Could not read clients request\n";
        }
        string serverMessage = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
        string response = "<html><h1>Hello World</h1></html>";
        serverMessage.append(to_string(response.size()));
        serverMessage.append("\n\n");
        serverMessage.append(response);

        int bytesSent = 0;
        int totalBytesSent = 0;
        while (totalBytesSent < serverMessage.size()){
            bytesSent = send(new_wsocket, serverMessage.c_str(), serverMessage.size(), 0);
            if (bytesSent<0){
                cout<<"Something went Wrong\n";
            }
            totalBytesSent += bytesSent;
        }
        cout<<"Sent response to client\n";
        closesocket(new_wsocket);
     }
     closesocket(wsocket);
    return 0;
}



