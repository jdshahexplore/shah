package maximum;
/**
 *
 * @author shah jainam
 */
import java.util.Scanner;
public class Maximum
{
    public static void main(String args[])
    {
        int i,max=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n = ");
        int n=sc.nextInt();
        int a[]=new int[n];
        System.out.println("enter " + n + " numbers");
        for(i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        System.out.print("maximum of entered numbers = ");
        for(i=0;i<n;i++)
        {
            if(max<=a[i])
                max=a[i];
        }
        System.out.println(max);
        sc.close();
    }
}