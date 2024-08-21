/*
Que. Write a program to demonstrate Sub-netting and find subnet masks.
*/

#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

class subnet
{
    public:
        string block;
        int subnet_bits;
        string temp;
        string binary_num;
        
        void get_data()
        {
            cout<<"\nEnter Block Address : ";
            cin>>block;
            cout<<"\nEnter Subnet Bits : ";
            cin>>subnet_bits;
        }

        void find_class()
        {
            string s1=block.substr(0,3);
            int s2=stoi(s1);
            if (s2 >= 1 && s2 <= 126)
            {
                cout << "\nClass A";
                cout << "\nDefault Subnet Mask : 255.0.0.0\n";
           
            }
            else if (s2 >= 128 && s2 <= 191)
            {
                cout << "\nClass B";
                cout << "\nDefault Subnet Mask : 255.255.0.0\n";
               
            }
            else if (s2 >= 192 && s2 <= 223)
            {
                cout << "\nClass C";
                cout << "\nDefault Subnet Mask : 255.255.255.0\n";
               
            }
        }

        void dec_to_bin()
        {
            int i = 0;
            while (i < block.length())
            {
                temp = "";
                while (i < block.length() && block[i] != '.')
                {
                    temp += block[i];
                    i++;
                }
                int num = stoi(temp);
                string binary_temp = "";
                while (num > 0)
                {
                    binary_temp = to_string(num % 2) + binary_temp; // Append the binary digit to the front of binary_temp
                    num = num / 2;
                }
                while(binary_temp.length()<8)
                {
                    binary_temp= "0" + binary_temp;
                }
               
                binary_num += binary_temp;
                if (i < block.length())
                {
                    binary_num += '.'; // Add a dot if there are more octets in the IP address
                    i++;
                }
            }
            cout<<"\nBlock Address (Binary) : "<<binary_num<<"\n";
        }

        int bin_to_dec(string pp)
        {
            int dec_value=0;
            int n = pp.size();
            for (int i = n - 1; i >= 0; i--)
            {
                if (pp[i] == '1')
                {
                    dec_value += pow(2, n - 1 - i);
                }
            }
            return dec_value;
        }

        void first_ip()
        {
            string sub_mask="";
            string fip="";
            int co=subnet_bits;
            while(co>0)
            {
                sub_mask+="1";
                co--;
            }

            int q=sub_mask.length();

            while(q<32)
            {
                sub_mask+="0";
                q++;
            }
           
            cout<<"\nSubnet Mask (Binary): "<<sub_mask<<"\n";
            string no_dots="";
            for(char c : binary_num)
            {
                if(c!='.')
                {
                    no_dots+=c;
                }
            }
            cout<<"\nBlock Address (Binary) : "<<no_dots<<"\n";

            for(int i=0,j=0;i<32,j<32;i++,j++)
            {
                fip+=no_dots[i] & sub_mask[j];
            }

            fip.insert(8,".");
            fip.insert(17,".");
            fip.insert(26,".");
           
            string first_ip="";
            first_ip += to_string(bin_to_dec(fip.substr(0, 8)));
            first_ip+=".";                                                    
            first_ip += to_string(bin_to_dec(fip.substr(9, 8)));
            first_ip+=".";                                                    
            first_ip += to_string(bin_to_dec(fip.substr(18, 8)));
            first_ip+=".";                                                  
            first_ip += to_string(bin_to_dec(fip.substr(27, 8)));

            cout<<"\nFirst IP Address (Binary) : "<<fip<<endl;
            cout<<"\nFirst IP Address (Decimal) : "<<first_ip<<endl;
        }

        void last_ip()
        {
            string subnet_mask = "";
            string lip = "";
            int m=subnet_bits;
            while(m > 0)
            {
                subnet_mask += "0";
                m--;
            }
            int q = subnet_mask.length();
            while(q < 32)
            {
                subnet_mask += "1";
                q++;
            }
            cout << "\nSubnet Mask (Binary) : " << subnet_mask<<"\n";
            string nope_dots = "";
            for(char d : binary_num)
            {
                if(d != '.')
                {
                    nope_dots += d;
                }
            }
            cout << "\nBlock Address (Binary) : " << nope_dots<<"\n";
           
            for(int i = 0, j = 0; i < 32, j < 32; i++, j++)
            {
                lip += (nope_dots[i] | subnet_mask[j]);
            }
            lip.insert(8, ".");
            lip.insert(17, ".");
            lip.insert(26, ".");
           
            string last_ip = "";
            last_ip += to_string(bin_to_dec(lip.substr(0, 8)));
            last_ip += ".";
            last_ip += to_string(bin_to_dec(lip.substr(9, 8)));
            last_ip += ".";
            last_ip += to_string(bin_to_dec(lip.substr(18, 8)));
            last_ip += ".";
            last_ip += to_string(bin_to_dec(lip.substr(27, 8)));

            cout << "\nLast IP Address (Binary) : " << lip<<endl;
            cout << "\nLast IP Address (Decimal) : " << last_ip<<endl;
        }

        void no_host()
        {
            int n=subnet_bits;
            int host=pow(2,32-n) - 2;
            cout<<"\nTotal Number of Hosts: "<<host<<"\n";
        }
};

int main()
{
    subnet s;
    s.get_data();
    s.find_class();
    s.dec_to_bin();
    s.first_ip();
    s.last_ip();
    s.no_host();
    return 0;
}

/*
OUTPUT

Enter Block Address : 192.168.2.64

Enter Subnet Bits : 27

Class C
Default Subnet Mask : 255.255.255.0

Block Address (Binary) : 11000000.10101000.00000010.01000000

Subnet Mask (Binary): 11111111111111111111111111100000

Block Address (Binary) : 11000000101010000000001001000000

First IP Address (Binary) : 11000000.10101000.00000010.01000000

First IP Address (Decimal) : 192.168.2.64

Subnet Mask (Binary) : 00000000000000000000000000011111

Block Address (Binary) : 11000000101010000000001001000000

Last IP Address (Binary) : 11000000.10101000.00000010.01011111

Last IP Address (Decimal) : 192.168.2.95

Total Number of Hosts: 30
*/
