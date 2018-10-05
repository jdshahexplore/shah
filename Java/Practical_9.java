import java.util.Scanner;

class Student
{
	int roll_no;
	String name;
	String address;
	String branch;
	
	void getdetails()
	{
		Scanner get = new Scanner (System.in);
		System.out.print("Enter Roll No : ");
		roll_no = get.nextInt();
		get.nextLine();
		System.out.print("Enter Name : ");
		name = get.nextLine();
		System.out.print("Enter address : ");
		address = get.nextLine();
		System.out.print("Enter branch : ");
		branch = get.nextLine();
	}
	
	void display()
	{
		System.out.println("Roll No : "+roll_no);
		System.out.println("Name : "+name);
		System.out.println("Address : "+address);
		System.out.println("Branch : "+branch);
	}
}

public class Practical_9
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner (System.in);
		int n;
		System.out.print("Enter n : ");
		n = s.nextInt();
		Student[] stu = new Student[n];
		System.out.println("Enter Details\n\n");
		for (int i=0;i<n;i++)
		{
			stu[i] = new Student();
			System.out.println("Student "+(i+1));
			stu[i].getdetails();
			System.out.println();
		}
		System.out.println("\nDetail Output\n");
		for (int i=0;i<n;i++)
		{
			System.out.println("Student "+(i+1));
			stu[i].display();
			System.out.println();
		}
	}
}
