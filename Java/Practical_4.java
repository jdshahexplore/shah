import java.util.Scanner;

class Practical_4
{
	public static int len(String s)
	{
		int n;
		n = s.length();
		return n;
	}
	
	public static void display(char[] s,int n)
	{
		System.out.println("Length : "+n);
		System.out.print("Half String : ");
		for (int i=0; i<(n+1)/2; i++)
			System.out.print(s[i]);
		System.out.println();
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner (System.in);
		String str;
		System.out.print("Enter String : ");
		str = sc.nextLine();
		int n = len(str);
		display(str.toCharArray(),n);
	}
}
