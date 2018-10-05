#include<iostream>
using namespace std;

int iter=0;

int C(int n,int k)
{
	iter++;
	if(k==0 || k==n)
		return 1;
	else
		return C(n-1,k-1)+C(n-1,k);
}

int main()
{
	int n,k;
	cout<<"Enter n = ";
	cin>>n;
	cout<<"Enter k = ";
	cin>>k;
	cout<<"C(n,k) = "<<C(n,k);
	cout<<"\niter = "<<iter<<endl;
	return 0;
}
