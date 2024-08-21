
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() 
{
    FILE *fp;
    WSADATA wsa;
    SOCKET sd, newsd;
    int ser, n, bd, port, clilen;
    char name[100], fileread[100], fname[100], rcv[100];
    struct sockaddr_in servaddr, cliaddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        printf("Failed to initialize Winsock\n");
        return 1;
    }

    printf("Enter the port address: ");
    scanf("%d", &port);

    // Create a socket
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 
    {
        printf("Can't create socket\n");
        WSACleanup();
        return 1;
    } 
    else 
    {
        printf("Socket is created\n");
    }

    // Server Address Setup
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    clilen = sizeof(cliaddr);

    // Bind the socket to the server address
    if (bind(sd, (struct sockaddr *)&servaddr, clilen) == SOCKET_ERROR) 
    {
        printf("Can't bind\n");
        closesocket(sd);
        WSACleanup();
        return 1;
    } 
    else 
    {
        printf("Binded\n");
    }

    // Listen for incoming connections
    listen(sd, 5);

    // Accept client connection
    newsd = accept(sd, (struct sockaddr *)&cliaddr, &clilen);

    if (newsd == INVALID_SOCKET) 
    {
        printf("Can't accept\n");
        closesocket(sd);
        WSACleanup();
        return 1;
    } 
    else 
    {
        printf("Accepted\n");
    }

    // Receive file name from the client
    n = recv(newsd, rcv, 100, 0);
    rcv[n] = '\0';
    fp = fopen(rcv, "r");

    // File Transfer
    if (fp == NULL) 
    {
        send(newsd, "error", 5, 0);
        closesocket(newsd);
    } 
    else 
    {
        while (1) 
        {
            size_t bytesRead = fread(fileread, 1, sizeof(fileread), fp);
            if (bytesRead > 0) 
            {
                if (send(newsd, fileread, bytesRead, 0) == SOCKET_ERROR) 
                {
                    printf("Can't send\n");
                    break;
                }
            } 
            else 
            {
                send(newsd, "completed", 9, 0);
                break;
            }
        }
        fclose(fp);
        closesocket(newsd);
    }

    // Cleanup
    closesocket(sd);
    WSACleanup();

    return 0;
}

/*
OUTPUT

PS C:\Users\purva\Documents\cns> gcc -o server tcpserver.c -lws2_32  
>> 
PS C:\Users\purva\Documents\cns> ./server.exe                        
>> 
Enter the port address: 12345
Socket is created
Binded
Accepted

*/
