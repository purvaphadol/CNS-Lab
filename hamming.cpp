/*
Que. Write a program for error detection and correction for 7/8 bits ASCII codes using Hamming Codes.
*/

#include<iostream>
#include<cmath>
using namespace std;

class hamming
{
    public:
        int pos[8];
        int rec[8];
        int err[3];
        int a1,a2,a3;
        
        void get_data()
        {
            pos[0]=0;
            cout<<"\nEnter the four bits : ";
            cout<<"\nBit 7 : ";
            cin>>pos[7];
            cout<<"\nBit 6 : ";
            cin>>pos[6];
            cout<<"\nBit 5 : ";
            cin>>pos[5];
            cout<<"\nBit 3 : ";
            cin>>pos[3];
        }

        void calculate_parity()
        {
            pos[1]=pos[3]^pos[5]^pos[7];
            pos[2]=pos[3]^pos[6]^pos[7];
            pos[4]=pos[5]^pos[6]^pos[7];
            cout<<"\nSender's Data is : ";
            for(int i=7;i>0;i--)
            {
            	cout<<pos[i]<<" ";
            }
            cout<<"\n\nParity : ";
            cout<<"\nP4 P2 P1";
            cout<<"\n"<<pos[4]<<" "<<pos[2]<<" "<<pos[1];
        }

        void receive_bits()
        {
            rec[0]=0;
            cout<<"\nEnter the received seven bits : ";
            for(int i=7;i>0;i--)
            {
                cout<<"\nEnter bit at position "<<i<<" : ";
                cin>>rec[i];
            }
            
            cout<<"\nReceived Data : ";
            for(int i=7;i>0;i--)
            {
                cout<<rec[i]<<" ";
            }
        }

        void parity_received()
        {
            err[0]=rec[1]^rec[3]^rec[5]^rec[7];
            err[1]=rec[2]^rec[3]^rec[6]^rec[7];
            err[2]=rec[4]^rec[5]^rec[6]^rec[7];
        }

        void display_errors()
        {
            cout<<"\nThe detected errors are : ";
            cout<<"\nP4 P2 P1";
            cout<<"\n"<<err[2]<<" "<<err[1]<<" "<<err[0];
        }

        void correction()
        {
            int decimal=0;
            for(int i=0;i<3;i++)
            {
                decimal+=err[i]*pow(2,i);
            }

            cout<<"\nThe bit at position "<<decimal<<" should be changed!";
            if(rec[decimal]==1)
            {
                rec[decimal]=0;
            }
            else
            {
                rec[decimal]=1;
            }
        }

        void display_output()
        {
            cout<<"\nFinally, the corrected code is : ";
             for(int i=7;i>0;i--)
            {
                cout<<rec[i]<<" ";
            }
        }
};

int main()
{
    hamming obj;
    obj.get_data();
    obj.calculate_parity();
    obj.receive_bits();
    obj.parity_received();

    cout<<"\n";
    obj.display_errors();
    cout<<"\n";
    obj.correction();
    cout<<"\n";
    obj.display_output();
    return 0;
}

/*
Output

kkw@kkw-HP-280-Pro-G6-Microtower-PC:~/Desktop/B_58$ g++ hamming.cpp
kkw@kkw-HP-280-Pro-G6-Microtower-PC:~/Desktop/B_58$ ./a.out

Enter the four bits : 
Bit 7 : 1

Bit 6 : 0

Bit 5 : 1

Bit 3 : 1

Sender's Data is : 1 0 1 0 1 0 1 

Parity : 
P4 P2 P1
0 0 1

Enter the received seven bits : 
Enter bit at position 7 : 1

Enter bit at position 6 : 1

Enter bit at position 5 : 1

Enter bit at position 4 : 0

Enter bit at position 3 : 1

Enter bit at position 2 : 0

Enter bit at position 1 : 1

Received Data : 1 1 1 0 1 0 1 

The detected errors are : 
P4 P2 P1
1 1 0

The bit at position 6 should be changed!

Finally, the corrected code is : 1 0 1 0 1 0 1 

*/
