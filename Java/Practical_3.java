import java.util.Scanner;

class SortNumber
{
	public static void sort(int[] a,int n)
	{
		int temp;
		for (int i=1; i<n; i++)
			for (int j=0; j<i; j++)
				if (a[i] < a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
	}
}

public class Practical_3
{
	public static void main(String[] args)
	{
		int n = Integer.parseInt(args[0]);
		int[] num = new int[n];
		Scanner sc = new Scanner (System.in);
		for (int i=1; i<=n; i++)
		{
			num[i-1] = Integer.parseInt(args[i]);
		}
		SortNumber s = new SortNumber();
		s.sort(num,n);
		System.out.println("-------------Sorted Numbers------------");
		for (int i=0; i<n; i++)
			System.out.print(num[i]+"\t");
		System.out.println();
	}
}
