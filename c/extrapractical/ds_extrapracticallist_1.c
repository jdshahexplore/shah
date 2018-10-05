#include<stdio.h>
#include<string.h>
#define size 20

struct stack
{
	int binary[size],top;
	char string[size];
}st;

int isfull()
{
	if(st.top==size-1)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(st.top==-1)
		return 1;
	else
		return 0;
}

void bpush(int x)
{
	st.top++;
	st.binary[st.top]=x;
}

void spush(char x)
{
    st.top++;
    st.string[st.top]=x;
}

int bpop()
{
	int x;
	x=st.binary[st.top];
	st.top--;
	return x;
}

char spop()
{
    char x;
    x=st.string[st.top];
    st.top--;
    return x;
}

main()
{
	int n,x,c,len,i,p,m;
	char str[20];
	read:
	st.top=-1;
	printf(" Type 1 to reverse a string \n Type 2 to convert decimal to binary \n Type 3 to check string is palindrome\n Type 4 to exit \n");
	printf("enter your choice = ");
	scanf("%d",&c);
	switch(c)
	{
        case 1:
            printf("enter a string = ");
            scanf("%s",str);
            len=strlen(str);
            for(i=0;i<len;i++)
            {
                spush(str[i]);
            }
            while(!isempty())
            {
                printf("%c",spop());
            }
            printf("\n\n");
            goto read;
        case 2:
            printf("enter number = ");
            scanf("%d",&n);
            while(n!=0)
            {
                if(isfull())
                    printf("please enter small number");
                else
                {
                    x=n%2;
                    bpush(x);
                    n=n/2;
                }
            }
            while(!isempty())
            {
                printf("%d",bpop());
            }
            printf("\n\n");
            goto read;
       	case 3:
       		p=0,m=0;
        	printf("enter a string = ");
        	scanf("%s",str);
        	len=strlen(str);
        	if(len%2!=0)
        	{
        		for(i=0;i<len;i++)
            	{	
                	spush(str[i]);
                	if(str[i]=='x')
             		   	p++;
            	}
            	if(p==1)
            	{
            		if(str[len/2]=='x')
            		{
            			for(i=0;i<len;i++)
            			{
            				if(str[i]==spop())
            					m++;
						}
						if(m==len)
							printf("string is palindrome\n\n");
						else
							printf("string is not palindrome\n\n");
					}
					else
						printf("string is not palindrome\n\n");
				}	
				else
					printf("string is not palindrome\n\n");
			}
			else
				printf("string is not palindrome\n\n");
			goto read;
        case 4:
        	break;
	}
}
