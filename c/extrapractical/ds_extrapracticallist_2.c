#include<stdio.h>
#include<string.h>
#define size 50

struct stack
{
	char str[size];
	int top;
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

void push(char x)
{
	st.top++;
	st.str[st.top]=x;
}

char pop()
{
	char x;
	x=st.str[st.top];
	st.top--;
	return x;
}

int incomingp(char x)
{
	int p;
	switch(x)
	{
		case '+':p=2;break;
		case '-':p=2;break;
		case '*':p=4;break;
		case '/':p=4;break;
		case '^':p=5;break;
		case '(':p=0;break;
		case ')':p=9;break;
	}
	return p;
}

int instackp(char x)
{
	int p;
	switch(x)
	{
		case '$':p=-1;break;
		case '+':p=1;break;
		case '-':p=1;break;
		case '*':p=3;break;
		case '/':p=3;break;
		case '^':p=6;break;
		case ')':p=0;break;
	}
	return p;
}

void main()
{
    char ch,infix[size],prefix[size],temp[size],x,output[size];
    int i,j=0;
    st.top=-1;

    printf("enter string = ");
    scanf("%s",infix);

    for(i=0;infix[i]!='\0';i++)
    {
        push(infix[i]);
    }
    i=0;
    while(!isempty())
    {
        x=pop();
        temp[i]=x;
        i++;
    }

    push('$');

    for(i=0;temp[i]!='\0';i++)
    {
        ch=temp[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            prefix[j]=ch;
            j++;
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        {
            while(instackp(st.str[st.top])>incomingp(ch))
            {
                x=pop();
                prefix[j]=x;
                j++;
            }
            push(ch);
        }
        else if(ch==')')
            push(ch);
        else if(ch=='(')
        {
            while((x=pop())!=')')
            {
                prefix[j]=x;
                j++;
            }
        }
    }
    while(!isempty())
    {
        x=pop();
        prefix[j]=x;
        j++;
    }
    prefix[j-1]='\0';
    
	push('$');
    for(i=0;prefix[i]!='\0';i++)
    {
        push(prefix[i]);
    }
    i=0;
    while((x=pop())!='$')
    {
        output[i]=x;
        i++;
    }

    printf("output string = %s",output);
}
