/*
Que. Write a program to implement Distance vector routing protocol to find suitable path for transmission.
*/

#include <iostream>
using namespace std;

const int INF = 999; // Infinity for unreachable nodes

struct node 
{
    int dist[6];
    int from[6];
} DVR[10];

int main() 
{
    cout << "\n\n---------- Distance Vector Routing ----------";
    int costmat[6][6];
    int nodes, i, j, k;

    cout << "\n\nEnter the number of nodes: ";
    cin >> nodes;

    cout << "\nEnter the cost matrix (use '999' for no direct connection):\n";
    for (i = 0; i < nodes; i++) 
    {
        for (j = 0; j < nodes; j++) 
        {
            cin >> costmat[i][j];
            if (i != j && costmat[i][j] == 999) 
            {
                costmat[i][j] = INF; // Set non-diagonal elements to infinity initially
            }
            DVR[i].dist[j] = costmat[i][j];
            DVR[i].from[j] = j;
        }
    }

    for (int iteration = 1; iteration < nodes; iteration++) 
    {
        for (i = 0; i < nodes; i++) 
        {
            for (j = 0; j < nodes; j++) 
            {
                for (k = 0; k < nodes; k++) 
                {
                    if (DVR[i].dist[j] > costmat[i][k] + DVR[k].dist[j]) 
                    {
                        DVR[i].dist[j] = costmat[i][k] + DVR[k].dist[j];
                        DVR[j].dist[i] = DVR[i].dist[j];
                        DVR[i].from[j] = k;
                        DVR[j].from[i] = k;
                    }
                }   
            }
        }
    }

    cout << "\n\nFinal Routing Table:\n";
    cout << "----------------------------------------------\n";
    cout << "Node\tDestination\tDistance\tNextNode\n";
    cout << "----------------------------------------------\n";

    for (i = 0; i < nodes; i++) 
    {
        for (j = 0; j < nodes; j++) 
        {
            cout << i + 1 << "\t" << j + 1 << "\t\t" << DVR[i].dist[j] << "\t\t" << DVR[i].from[j] + 1 << "\n";
        }
        cout << "----------------------------------------------\n";
    }

    return 0;
}

/*
Output

---------- Distance Vector Routing ----------

Enter the number of nodes: 4

Enter the cost matrix (use '999' for no direct connection):
0
2
999
1
2
0
3
7
999
3
0
11
1
7
11
0


Final Routing Table:
----------------------------------------------
Node    Destination     Distance        NextNode
----------------------------------------------
1       1               0               1
1       2               2               2
1       3               5               2
1       4               1               4
----------------------------------------------
2       1               2               1
2       2               0               2
2       3               3               3
2       4               3               1
----------------------------------------------
3       1               5               2
3       2               3               2
3       3               0               3
3       4               6               2
----------------------------------------------
4       1               1               1
4       2               3               1
4       3               6               2
4       4               0               4
----------------------------------------------
*/
