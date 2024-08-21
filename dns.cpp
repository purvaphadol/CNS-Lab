/*
Que. Write a program for DNS lookup. Given an IP address as input, it should return URL and vice-versa.
*/
#include <iostream>
#include <string>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
using namespace std;

int main() 
{
    int n;
    do 
    {
        cout << "\n Menu: \n 1. DNS 2. Reverse DNS 3. Exit \n";
        cout << "\n Enter your choice: ";
        cin >> n;

        if (n == 1) 
        {
            try 
            {
                cout << "\n Enter Host Name: ";
                string hname;
                cin >> hname;
                struct hostent* host = gethostbyname(hname.c_str());

                if (host != nullptr) 
                {
                    cout << "Host Name: " << host->h_name << endl;
                    cout << "IP: " << inet_ntoa(*reinterpret_cast<struct in_addr*>(host->h_addr_list[0])) << endl;
                } 
                else 
                {
                    cerr << "Error: Host not found" << endl;
                }
            } 
            catch (...) 
            {
                cerr << "An error occurred." << endl;
            }
        }
        if (n == 2) 
        {
            try 
            {
                cout << "\n Enter IP address: ";
                string ipstr;
                cin >> ipstr;
                struct sockaddr_in sa;
                memset(&sa, 0, sizeof(struct sockaddr_in));
                sa.sin_family = AF_INET;
                sa.sin_addr.s_addr = inet_addr(ipstr.c_str());
                char hostBuffer[NI_MAXHOST];

                if (getnameinfo((struct sockaddr*)&sa, sizeof(struct sockaddr), hostBuffer, sizeof(hostBuffer), NULL, 0, 0) == 0) 
                {
                    cout << "IP: " << ipstr << endl;
                    cout << "Host Name: " << hostBuffer << endl;
                } 
                else 
                {
                    cerr << "Error: IP not found or has no reverse DNS entry" << endl;
                }
            } 
            catch (...) 
            {
                cerr << "An error occurred." << endl;
            }
        }
    } 
    while (n != 3);
    return 0;
}

/*
OUTPUT

***Menu***
1.DNS 
2.Reverse DNS 
3.Exit 

 Enter your choice: 1
 Enter Host Name: www.google.com
 Host Name: www.google.com
IP: 172.217.214.104

***Menu***
1.DNS 
2.Reverse DNS 
3.Exit 

 Enter your choice: 2
 Enter IP address: 172.217.214.104
 IP: 172.217.214.104
Host Name: jr-in-f104.1e100.net

***Menu***
1.DNS 
2.Reverse DNS 
3.Exit 

 Enter your choice: 3
 Exit

*/