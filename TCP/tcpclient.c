
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() 
{
    FILE *fp;
    WSADATA wsa;
    SOCKET csd;
    int n, s, cport;
    char name[100], rcvg[100], fname[100];
    struct sockaddr_in servaddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        printf("Failed to initialize Winsock\n");
        return 1;
    }

    printf("Enter the port: ");
    scanf("%d", &cport);

    // Create a socket
    if ((csd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 
    {
        printf("Error creating socket\n");
        WSACleanup();
        return 1;
    } 
    else 
    {
        printf("Socket is created\n");
    }

    // Server Address Setup
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Use INADDR_LOOPBACK for local connection
    servaddr.sin_port = htons(cport);

    // Connect to the server
    if (connect(csd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == SOCKET_ERROR) 
    {
        perror("Error in connection");
        closesocket(csd);
        WSACleanup();
        return 1;
    } 
    else 
    {
        printf("Connected to the server\n");
    }

    // Input: File names
    printf("Enter the existing file name: ");
    scanf("%s", name);
    printf("Enter the new file name: ");
    scanf("%s", fname);

    fp = fopen(fname, "wb"); // Open file in binary mode for writing

    if (fp == NULL) 
    {
        printf("Error opening file for writing\n");
        closesocket(csd);
        WSACleanup();
        return 1;
    }

    send(csd, name, strlen(name), 0); // sends data to the server using a socket

    while (1) 
    {
        s = recv(csd, rcvg, 100, 0);
        if (s <= 0) 
        {
            // Handle error or end of transmission
            break;
        }
        fwrite(rcvg, 1, s, fp);
        if (strcmp(rcvg, "completed") == 0) 
        {
            printf("File is transferred\n");
            fclose(fp);
            closesocket(csd); // closes the socket
            break;
        }
    }

    // Cleanup
    closesocket(csd);
    WSACleanup();

    return 0;
}

/*
OUTPUT

PS C:\Users\purva\Documents\cns> gcc -o client tcpclient.c -lws2_32
>>
PS C:\Users\purva\Documents\cns> ./client.exe
>> 
Enter the port: 12345
Socket is created
Connected to the server
Enter the existing file name: try.txt
Enter the new file name: new.txt

*/
