
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() 
{
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in serverAddr;
    int port;
    char existingFileName[100];
    FILE *existingFile;
    FILE *newFile;
    char newFileName[100];
    char buffer[100];

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
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
    serverAddr.sin_port = htons(port);

    printf("Enter the name of the existing file: ");
    scanf("%s", existingFileName);

    // Open the existing file for reading
    existingFile = fopen(existingFileName, "r");
    if (existingFile == NULL) 
    {
        printf("Error opening existing file\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("Enter the name of the new file: ");
    scanf("%s", newFileName);

    // Create a new file for writing
    newFile = fopen(newFileName, "w");
    if (newFile == NULL) 
    {
        printf("Error creating new file\n");
        fclose(existingFile);
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // Read the contents of the existing file and send them to the server
    while (fgets(buffer, sizeof(buffer), existingFile) != NULL) 
    {
        // Write the contents to the new file
        fprintf(newFile, "%s", buffer);

        // Send data to server
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) 
        {
            printf("Error sending data\n");
            fclose(existingFile);
            fclose(newFile);
            closesocket(sockfd);
            WSACleanup();
            return 1;
        }
    }

    // Send the exit command to the server
    sendto(sockfd, "exit", strlen("exit"), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    fclose(existingFile);
    fclose(newFile);

    printf("File contents sent to the server and written to %s\n", newFileName);

    // Cleanup
    closesocket(sockfd);
    WSACleanup();

    return 0;
}

/*
OUTPUT

PS C:\Users\purva\Documents\cns> gcc -o client udpclient.c -lws2_32
>> 
PS C:\Users\purva\Documents\cns> ./client.exe
>> 
Enter the port for UDP server: 12345
Enter the name of the existing file: sample.txt
Enter the name of the new file: new_file.txt
File contents sent to the server and written to new_file.txt

*/
