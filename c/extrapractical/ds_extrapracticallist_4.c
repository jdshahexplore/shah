#include<stdio.h>
#include<math.h>
#define size 50
//declaration of structure
struct stack
{
	char str[size];
	int top,eval[size];
}st;
//checking full condition
int isfull()
{
	if(st.top==size-1)
		return 1;
	else
		return 0;
}
//checking empty condition
int isempty()
{
	if(st.top==-1)
		return 1;
	else
		return 0;
}
//push operation
void push(char x)
{
	st.top++;
	st.str[st.top]=x;
}
//pop operation
char pop()
{
	char x;
	x=st.str[st.top];
	st.top--;
	return x;
}
//push_int
void push_int(int x)
{
	st.top++;
	st.eval[st.top]=x;
}
//pop_int
int pop_int()
{
	int x;
	x=st.eval[st.top];
	st.top--;
	return x;
}
//income operator priority
int incomingp(char x)
{
	int p;
	switch(x)
	{
		case '+':
		case '-':
			p=1;break;
		case '*':
		case '/':
			p=3;break;
		case '^':p=6;break;
		case '(':p=9;break;
		case ')':p=0;break;
	}
	return p;
}
//instack operator priority
int instackp(char x)
{
	int p;
	switch(x)
	{
		case '$':p=-1;break;
		case '+':
		case '-':
			p=2;break;
		case '*':
		case '/':
			p=4;break;
		case '^':p=5;break;
		case '(':p=0;break;
	}
	return p;
}
//evaluate
int evaluate(char s[])
{
	int a[size],i=0,j;
	char ch,op1,op2;
	st.top=-1;
	while(s[i]!='\0')
	{
		ch=s[i];
		if(isalpha(ch))
		{
			if(isupper(ch))
				j=(int)ch-65;
			else
				j=(int)ch-97;
			printf("enter value for '%c' = ",ch);
			scanf("%d",&a[j]);
			push_int(a[j]);
		}
		else
		{
			op2=pop_int();
			op1=pop_int();
			switch(ch)
			{
				case '+':
					push_int(op1+op2);
					break;
				case '-':
					push_int(op1-op2);
					break;
				case '*':
					push_int(op1*op2);
					break;
				case '/':
					push_int(op1/op2);
					break;
				case '^':
					push_int(pow(op1,op2));
					break;
			}
		}
		i++;
	}
	j=pop_int();
	return j;
}
//main function
void main()
{
	char infix[size],postfix[size],ch,x;
	int i,j;
	st.top=-1;
	j=0;
	push('$');
	printf("enter expression = ");
	scanf("%s",infix);
	for(i=0;infix[i]!='\0';i++)
	{
		ch=infix[i];
		if(isalpha(ch))
		{
			postfix[j]=ch;
			j++;
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		{
			while(instackp(st.str[st.top])>incomingp(ch))
			{
				x=pop();
				postfix[j]=x;
				j++;
			}
			push(ch);
		}
		else if(ch=='(')
			push('(');
		else
		{
			while((x=pop())!='(')
			{
				postfix[j]=x;
				j++;
			}
		}
	}
	while(!isempty())
	{
		x=pop();
		postfix[j]=x;
		j++;
	}
	postfix[j-1]='\0';
	printf("output string\n");
	printf("%s",postfix);
	i=evaluate(postfix);
	printf("\n\nanswer of expression = %d",i);
}
