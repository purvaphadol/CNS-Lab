
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() 
{
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);
    int port;

    printf("Enter the port for UDP server: ");
    scanf("%d", &port);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        printf("Failed to initialize Winsock\n");
        return 1;
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) 
    {
        printf("Error creating socket\n");
        WSACleanup();
        return 1;
    }

    // Server address setup
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) 
    {
        printf("Error binding socket\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("UDP server is waiting for incoming messages on port %d...\n", port);

    FILE *fp;
    char buffer[100];

    // Receive data from clients
    while (1) 
    {
        int bytesRead = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (bytesRead == SOCKET_ERROR) 
        {
            printf("Error receiving data\n");
            break;
        }

        buffer[bytesRead] = '\0';
        printf("Received message from %s:%d - %s\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), buffer);

        // Check for the exit command
        if (strcmp(buffer, "exit") == 0) 
        {
            printf("Server exiting...\n");
            break;
        }
    }

    // Cleanup
    closesocket(sockfd);
    WSACleanup();

    return 0;
}

/*
OUTPUT

PS C:\Users\purva\Documents\cns> gcc -o server udpserver.c -lws2_32
>> 
PS C:\Users\purva\Documents\cns> ./server.exe
>> 
Enter the port for UDP server: 12345
UDP server is waiting for incoming messages on port 12345...
Received message from 127.0.0.1:58892 - Hello

Received message from 127.0.0.1:58892 - This is UDP Socket Programming.

Received message from 127.0.0.1:58892 -

Received message from 127.0.0.1:58892 - exit
Server exiting...

*/

