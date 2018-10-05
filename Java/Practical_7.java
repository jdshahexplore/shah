import java.util.Scanner;

class Practical_7
{
	public static void reverse(char[] s,char[] r,int n)
	{
		for (int i=0; i<n; i++)
		{
			r[n-i-1] = s[i];
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner (System.in);
		String str1,str2;
		System.out.print("Enter Line : ");
		str1 = sc.nextLine();
		char[] s = new char[str1.length()];
		char[] r = new char[str1.length()];
		s = str1.toCharArray();
		reverse(s,r,str1.length());
		int c=0;
		for (int i=0; i<str1.length(); i++)
			if (s[i]==r[i])
				c++;
		if (c==str1.length())
			System.out.println("String is palindrome");
		else
			System.out.println("String is not palindrome");
	}
}
