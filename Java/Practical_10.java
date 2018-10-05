/*Write a simple java application that defines a class Complex with
real(int) and img(int) as data fields, no-argument constructor and parameterized
constructor. The class should have overloaded methods to perform addition of
two Complex numbers by passing objects as arguments.*/

import java.util.Scanner;
class Complex
{
	int real,img;
	Complex()
	{
		real=img=0;
	}
	Complex(int real,int img)
	{
		this.real=real;
		this.img=img;
	}
	Complex add(Complex c2)
	{
		Complex c3=new Complex();
		c3.real=this.real+c2.real;
		c3.img=this.img+c2.img;
		return c3;
	}
	void add(Complex c1,Complex c2)
	{
		c1.real=c1.real+c2.real;
		c1.img=c1.img+c2.img;
	}
	void display()
	{
		System.out.println(this.real+"+"+this.img+"i");
	}
}

class Practical_10
{
	public static void main(String args[])
	{
		Complex c1=new Complex(3,4);
		Complex c2=new Complex(4,7);
		Complex c3=new Complex();
		System.out.print("c1 = ");
		c1.display();
		System.out.print("c2 = ");
		c2.display();
		c3=c1.add(c2);
		System.out.print("c1 + c2 = ");
		c3.display();		
		c3.add(c1,c2);
		System.out.print("c1 + c2 = ");
		c3.display();		
	}
}
