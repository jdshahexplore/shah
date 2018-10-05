#include<iostream>
#include<string.h>
using namespace std;

void receiverside()
{
    char code[7];
    int s[3];
    cout<<endl<<"Enter a codeword = ";
    cin>>code;
	
	//calculating Syndrome bit
    s[0]=(code[1]+code[2]+code[3]+code[6])%2;
    s[1]=(code[0]+code[1]+code[2]+code[5])%2;
    s[2]=(code[0]+code[2]+code[3]+code[4])%2;
    
    switch(1*s[0]+2*s[1]+4*s[2])
    {
    	case 0:
    		cout<<"No error";break;
    	case 1:
    		code[6]=char(97-code[6]);
    		cout<<"q0 contains error";break;
    	case 2:
    		code[5]=char(97-code[5]);
    		cout<<"q1 contains error";break;
    	case 3:
    		code[1]=char(97-code[1]);
    		cout<<"b2 contains error";break;
    	case 4:
    		code[4]=char(97-code[4]);
    		cout<<"q2 contains error";break;
		case 5:
    		code[3]=char(97-code[3]);
    		cout<<"b0 contains error";break;
		case 6:
    		code[0]=char(97-code[0]);
    		cout<<"b3 contains error";break;
		case 7:
    		code[2]=char(97-code[2]);
    		cout<<"b1 contains error";break;	
	}
    
    cout<<"\nCorrected code = "<<code;
}

void senderside(char d[4])
{
	char code[7];
	
	for(int i=0;i<4;i++)
        code[i]=d[i];

    //calculating redundant bits
    code[4]=char((d[0]+d[2]+d[3])%2+48);
    code[5]=char((d[0]+d[1]+d[2])%2+48);
    code[6]=char((d[1]+d[2]+d[3])%2+48);

    cout<<"----codeword----"<<endl;
    
	cout<<code;
}

int main()
{
    char data[4];

    cout<<"Enter a 4-bit data = ";
    cin>>data;
    
    senderside(data);
	
    receiverside();
}
