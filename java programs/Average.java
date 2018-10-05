package average;
/**
 *
 * @author shah jainam
 */
import java.util.Scanner;
public class Average 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n,i,avg=0;
        System.out.print("enter n = ");
        n=s.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++)
        {
            a[i]=s.nextInt();
            avg+=a[i];
        }
        avg/=n;
        System.out.println("average of number = " + avg);
    }
    
}
