import java.util.Scanner;

class Practical_5
{
	public static void calculate(char s[],int n)
	{
		int cc = 0 ,cv = 0;
		for (int i=0; i<n; i++)
		{
			if (Character.isLetter(s[i]))
			{
				if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
					cv++;
				else
					cc++;
			}
		}
		System.out.println("Consonents : "+cc);
		System.out.println("Vowels : "+cv);
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner (System.in);
		String str;
		System.out.print("Enter line : ");
		str = sc.nextLine();
		str.toLowerCase();
		calculate(str.toCharArray(),str.length());
	}
}
