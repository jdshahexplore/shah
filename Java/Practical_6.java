import java.util.Scanner;

class Practical_6
{
	public static boolean checkcap(char c)
	{
		if (Character.isUpperCase(c))
			return true;
		else
			return false;
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner (System.in);
		String str;
		System.out.print("Enter String : ");
		str = sc.nextLine();
		int c=0,i=0;
		char[] s = new char[str.length()];
		s = str.toCharArray();
		if (checkcap(s[i++]))
			c++;
		while(i<str.length())
		{
			if (s[i++]==' ')
				if (checkcap(s[i++]))
					c++;
		}
		System.out.println("Total Count : "+c);
	}
}
