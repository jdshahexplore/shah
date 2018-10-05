#include<iostream>
using namespace std;

class matrix
{
	int m,n;
	int mat[3][3];
	public:
		matrix()
		{
			m=3,n=3;
		}
		void getdata()
		{
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					cin>>mat[i][j];
		}
		void putdata()
		{
			cout<<"------------------------------"<<endl;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<mat[i][j]<<"\t";
				}
				cout<<endl;
			}
			cout<<"------------------------------"<<endl<<endl;
		}
		matrix operator +(matrix &);
		matrix operator *(matrix &);
		void transpose(matrix &);
};

matrix matrix::operator +(matrix & m2)
{
	matrix m3;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			m3.mat[i][j]=mat[i][j]+m2.mat[i][j];
		}
	return m3;
}

matrix matrix::operator *(matrix & m2)
{
	matrix m3;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			m3.mat[i][j]=0;
			for(int k=0;k<n;k++)
				m3.mat[i][j]=m3.mat[i][j]+mat[i][k]*m2.mat[k][j];
		}
	return m3;
}

void matrix::transpose(matrix & m1)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			mat[i][j]=m1.mat[j][i];
}

int main()
{
	int c;
	matrix m1,m2,m3;	
	cout<<"1: Read matrix"<<endl;
	cout<<"2: Display matrix"<<endl;
	cout<<"3: Add two matrices"<<endl;
	cout<<"4: Multiply two matrices"<<endl;
	cout<<"5: Transpose of matrix"<<endl;
	cout<<"6: Exit"<<endl;
	read:
	cout<<"Enter choice = ";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"Enter data for matrix"<<endl;
			m1.getdata();
			goto read;
		case 2:
			cout<<endl;
			m1.putdata();
			goto read;
		case 3:
			cout<<"Enter data for 1st matrix"<<endl;
			m1.getdata();
			cout<<"Enter data for 2nd matrix"<<endl;
			m2.getdata();
			m3=m1+m2;
			cout<<endl<<"Addition of two matrix"<<endl;
			m3.putdata();
			goto read;
		case 4:
			cout<<"Enter data for 1st matrix"<<endl;
			m1.getdata();
			cout<<"Enter data for 2nd matrix"<<endl;
			m2.getdata();
			m3=m1*m2;
			m3.putdata();
			goto read;
		case 5:
			cout<<"Enter data for matrix"<<endl;
			m1.getdata();
			cout<<"Original matrix"<<endl;
			m1.putdata();
			m2.transpose(m1);
			cout<<"Transpose of matrix"<<endl;
			m2.putdata();
			goto read;
		case 6:
			break;
	}
	return 0;
}
