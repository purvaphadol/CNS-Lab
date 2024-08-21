/*
Que. Write a program to simulate Go back N Mode of Sliding Window Protocol in Peer-to-Peer mode.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int totalFrames;
    int windowSize;

    cout << "Enter the total number of frames: " ;
    cin >> totalFrames ;
    cout << "Enter the window size: " ;
    cin >> windowSize ;

    vector<int> window;

    for (int i = 1; i <= windowSize && i <= totalFrames; ++i) 
    {
        window.push_back(i);
    }

    int transmissions = 0;

    cout << "\nSending window: ";
    for (int j : window) 
    {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < totalFrames;) 
    {
        cout << "\nEnter acknowledgment for Frame " << window[0] << " (1: Received, 0: Not Received): ";
        int ack;
        cin >> ack;

        if (ack == 1) 
        {
            window.erase(window.begin());
            if (i + windowSize < totalFrames) 
            {
                window.push_back(i + windowSize + 1);
                cout << "Sent Frame " << i + windowSize + 1 << endl;
            }

            cout << "Updated window: ";
            for (int j : window) 
            {
                cout << j << " ";
            }
            cout << endl;
            i++;
        } 
        
        else 
        {
            cout << "Sending Current Window Again: ";
            for (int j : window) 
            {
                cout << j << " ";
            }
            cout << endl;
  
        }
        transmissions++;
    }

    cout << "\nAll frames transmitted successfully." << endl;
    cout << "Number of transmissions: " << windowSize + transmissions + 1 << endl;

    return 0;
}

/*
OUTPUT

Enter the total number of frames: 9
Enter the window size: 3

Sending window: 1 2 3

Enter acknowledgment for Frame 1 (1: Received, 0: Not Received): 1
Sent Frame 4
Updated window: 2 3 4

Enter acknowledgment for Frame 2 (1: Received, 0: Not Received): 1
Sent Frame 5
Updated window: 3 4 5

Enter acknowledgment for Frame 3 (1: Received, 0: Not Received): 1
Sent Frame 6
Updated window: 4 5 6

Enter acknowledgment for Frame 4 (1: Received, 0: Not Received): 1
Sent Frame 7
Updated window: 5 6 7

Enter acknowledgment for Frame 5 (1: Received, 0: Not Received): 0
Sending Current Window Again: 5 6 7

Enter acknowledgment for Frame 5 (1: Received, 0: Not Received): 1
Sent Frame 8
Updated window: 6 7 8

Enter acknowledgment for Frame 6 (1: Received, 0: Not Received): 1
Sent Frame 9
Updated window: 7 8 9

Enter acknowledgment for Frame 7 (1: Received, 0: Not Received): 0
Sending Current Window Again: 7 8 9

Enter acknowledgment for Frame 7 (1: Received, 0: Not Received): 1
Updated window: 8 9

Enter acknowledgment for Frame 8 (1: Received, 0: Not Received): 1
Updated window: 9

Enter acknowledgment for Frame 9 (1: Received, 0: Not Received): 0
Sending Current Window Again: 9

Enter acknowledgment for Frame 9 (1: Received, 0: Not Received): 1
Updated window:

All frames transmitted successfully.
Number of transmissions: 16





Enter the total number of frames: 10
Enter the window size: 4

Sending window: 1 2 3 4

Enter acknowledgment for Frame 1 (1: Received, 0: Not Received): 1
Sent Frame 5
Updated window: 2 3 4 5

Enter acknowledgment for Frame 2 (1: Received, 0: Not Received): 1
Sent Frame 6
Updated window: 3 4 5 6

Enter acknowledgment for Frame 3 (1: Received, 0: Not Received): 1
Sent Frame 7
Updated window: 4 5 6 7

Enter acknowledgment for Frame 4 (1: Received, 0: Not Received): 1
Sent Frame 8
Updated window: 5 6 7 8

Enter acknowledgment for Frame 5 (1: Received, 0: Not Received): 1
Sent Frame 9
Updated window: 6 7 8 9

Enter acknowledgment for Frame 6 (1: Received, 0: Not Received): 0
Sending Current Window Again: 6 7 8 9

Enter acknowledgment for Frame 6 (1: Received, 0: Not Received): 1
Sent Frame 10
Updated window: 7 8 9 10

Enter acknowledgment for Frame 7 (1: Received, 0: Not Received): 1
Updated window: 8 9 10

Enter acknowledgment for Frame 8 (1: Received, 0: Not Received): 0
Sending Current Window Again: 8 9 10

Enter acknowledgment for Frame 8 (1: Received, 0: Not Received): 1
Updated window: 9 10

Enter acknowledgment for Frame 9 (1: Received, 0: Not Received): 1
Updated window: 10

Enter acknowledgment for Frame 10 (1: Received, 0: Not Received): 1
Updated window:

All frames transmitted successfully.
Number of transmissions: 17

*/

