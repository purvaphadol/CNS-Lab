/*
Que. Write a program for error detection and correction for 7/8 bits ASCII codes using CRC.
*/

#include<iostream>
#define max 20
using namespace std;

class crc
{
	public:
	int divisor[max];
	int dividend[max];
	int temp[20];
	
	void division(int temp[], int divisor[], int nd,int nr)
	{
		for(int i=0; i<nd; i++) 
		{ 
			if(divisor[0]==temp[i]) 
			{ 
				for(int j=0, k=i; j<nr+1; j++, k++) 
				{ 
					if(!(temp[k]^divisor[j])) 
						temp[k]=0; 
					else 
						temp[k]=1;
				}
			} 
		}
		cout<<"\nCRC : ";
		for (int i=0; i<nr;i++)
		{
			cout<<temp[nd+i];
			dividend[nd+i]=temp[nd+i];
		}
	}
};

int main()
{
	int temp[20],divisor[20],dividend[20],nd, nr;
	crc c;
	cout<<"\nNo. of Bits present in Divisor : ";
	cin>>nr;
	cout<<"\nEnter Data "<<endl;
	for (int i=0; i<nr; i++)
	{
		cin>>divisor[i];
	}
	
	cout<<"\nDivisor : ";
	for (int i=0; i<nr; i++)
	{
		cout<<divisor[i];
	}
	cout<<endl;
	
	cout<<"\nNo. of Bits present in Dividend : ";
	cin>>nd;
	cout<<"\nEnter Data "<<endl;
	for (int i=0; i<nd; i++)
	{
		cin>>dividend[i];
	}
	nr--;
	for (int i=0; i<nr; i++)
	{
		dividend[nd+i]=0;
	}

	cout<<"\nDividend : ";
	for (int i=0; i<nd+nr ; i++)
	{
		cout<<dividend[i];
		temp[i]=dividend[i];
	}
	cout<<endl;
	
	c.division(temp,divisor,nd,nr);
	
	cout<<"\nEnter Received Message : "<<endl;
	for (int i=0; i<nd+nr; i++)
	{
		cin>>dividend[i];
		temp[i]=dividend[i];
	}
	c.division(temp,divisor,nd,nr);
	
	for (int i=0; i<nr; i++)
	{
		if (temp[nd+i])
		{
			cout<<"\nError Detected"<<endl;
			return 0;
		}
	}
	cout<<"\nNo Error"<<endl;
	cout<<"\nReceived Message : ";
	for (int i=0; i<nd ; i++)
	{
		cout<<dividend[i];
	}
	return 0;
}

/*
OUTPUT

No. of Bits present in Divisor : 4

Enter Data
1
0
1
1

Divisor : 1011

No. of Bits present in Dividend : 4

Enter Data
1
1
0
0

Dividend : 1100000

CRC : 010
Enter Received Message :
1
1
0
0
0
1
0

CRC : 000
No Error

Received Message : 1100
*/
