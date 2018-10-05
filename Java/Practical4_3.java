/*Write a simple java application that creates a Shape class with
 two double data members. The 
class should have one abstract method area to calculate the are
a of shape. Inherit two classes 
Rectangle and Triangle from Shape class. Demonstrate run time p
olymorphism.*/

import java.util.Scanner;
import java.lang.Math;

abstract class Shape
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
	
	abstract void area();
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

public class Practical4_3
{
	public static void main(String args[])
	{
		int ch;
		Scanner c=new Scanner(System.in);
		System.out.println("1: Rectangle\n2: Triangle");
		System.out.println("Enter choice = ");
		ch=c.nextInt();
		Shape s;
		switch(ch)
		{
			case 1:
				s=new Rectangle();
				s.area();
				break;
			case 2:
				s=new Triangle();
				s.area();
				break;
		}
	}
}
