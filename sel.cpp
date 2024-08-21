/*
Que. Write a program to simulate Selective Repeat Mode of Sliding Window Protocol in Peer-to-Peer mode.
*/

#include<iostream>
using namespace std;

int totalFrames;
int windowsize;

int main()
{
	cout<<"Enter total number of frames : ";
	cin>>totalFrames;
	cout<<"Enter window size : ";
	cin>>windowsize;
	
	int arr[windowsize];
	int currentFrameStart = 0;
	int currentFrameEnd = windowsize - 1;
	int transmissions=0;

	cout<<endl;
	for(int i = currentFrameStart;i<=currentFrameEnd && i<totalFrames;i++)
    {
		arr[i] = i;
		cout<<"\nFrames sent "<<arr[i]<<endl;
	}
	cout<<endl;

	int arrPointer = 0;
	char frameSent = 'Y';
	int currentFrame = windowsize;
	int countCheck = 0;

	while(countCheck < windowsize)
    {
		if(arr[arrPointer%windowsize] != -1)
        {
			cout<<"\nFrame "<<arr[arrPointer%windowsize]<<" received ? : ";
			cin>>frameSent;
			countCheck = 0;
			
			if(frameSent == 'Y' || frameSent == 'y')
            {
				if(currentFrame < totalFrames)
                {
					arr[arrPointer%windowsize] = currentFrame;
					cout<<"\nFrames sent "<<arr[arrPointer%windowsize]<<endl;
				} 
                else 
                {
					arr[arrPointer%windowsize] = -1;
				}
				
				currentFrame++;
				arrPointer++;
			} 
            else 
            {
				arrPointer++;	
			}
			transmissions ++;
		} 
        else 
        {
			arrPointer++;
			countCheck++;
		}   
	}
    cout << "\nAll frames transmitted successfully." << endl;
    cout << "Number of transmissions: " << transmissions << endl;
	return 0;
}

/*
OUTPUT

Enter total number of frames : 10
Enter window size : 4


Frames sent 0

Frames sent 1

Frames sent 2

Frames sent 3


Frame 0 received ? : y

Frames sent 4

Frame 1 received ? : y

Frames sent 5

Frame 2 received ? : y

Frames sent 6

Frame 3 received ? : y

Frames sent 7

Frame 4 received ? : y

Frames sent 8

Frame 5 received ? : n

Frame 6 received ? : y

Frames sent 9

Frame 7 received ? : y

Frame 8 received ? : y

Frame 5 received ? : y

Frame 9 received ? : n

Frame 9 received ? : y

All frames transmitted successfully.
Number of transmissions: 12

*/

