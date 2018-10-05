/*Write a simple java application that creates an interface Shape. 
 *The interface declares read() and show()  methods  and  PI  as  constant  data  member.
 *Create  classes  Rectangle  and  Circle  that implement shape interface. \
 *Assume suitable data and member methods.*/

import java.util.Scanner;
import java.lang.Math;

interface Shape
{
	double a,b;
	Shape()
	{
		Scanner sh=new Scanner(System.in);
		System.out.println("Enter side 1 : ");
		a=sh.nextDouble();
		System.out.println("Enter side 2 : ");
		b=sh.nextDouble();
	}
}

class Rectangle extends Shape
{
	Rectangle()
	{
		super();
	}
	
	void area()
	{
		System.out.println("Area of Rectangle : "+(a*b));
	}
}

class Triangle extends Shape
{
	double c;
	Triangle()
	{
		super();
		Scanner tr=new Scanner(System.in);
		System.out.println("Enter side 3 : ");
		c=tr.nextDouble();
	}
	
	void area()
	{
		Double p=(a+b+c)/2;
		System.out.println("Area of Triangle : "+(Math.sqrt(p*(p-a)*(p-b)*(p-c))));
	}
}

public class Practical4_2
{
	public static void main(String args[])
	{
		int ch;
		Scanner c=new Scanner(System.in);
		System.out.println("1: Rectangle\n2: Triangle");
		System.out.println("Enter choice = ");
		ch=c.nextInt();
		switch(ch)
		{
			case 1:
				Rectangle r=new Rectangle();
				r.area();
				break;
			case 2:
				Triangle t=new Triangle();
				t.area();
				break;
		}
	}
}
