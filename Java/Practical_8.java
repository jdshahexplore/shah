import java.util.Scanner;

public class Practical_8
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner (System.in);
		String str;
		StringBuffer c = new StringBuffer("quit");
		System.out.print("Enter String : ");
		str = sc.nextLine();
		while(!str.contentEquals(c))
		{
			char[] s = new char[str.length()];
			s = str.toCharArray();
			int ca=0,ce=0,ci=0,co=0,cu=0;
			for(int i=0;i<str.length();i++)
			{
				if (s[i]=='a')
					ca++;
				else if (s[i]=='e')
					ce++;
				else if (s[i]=='i')
					ci++;
				else if (s[i]=='o')
					co++;
				else if (s[i]=='u')
					cu++;
			}
			System.out.println("Count of a: "+ca);
			System.out.println("Count of e: "+ce);
			System.out.println("Count of i: "+ci);
			System.out.println("Count of o: "+co);
			System.out.println("Count of u: "+cu);
			System.out.print("Enter String : ");
			str = sc.nextLine();
		}
	}
}
