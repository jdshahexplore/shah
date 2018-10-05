package sum_odd;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Sum_odd 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n,i,sum=0;
        System.out.print("enter n = ");
        n=s.nextInt();
        for(i=1;i<(2*n);i+=2)
            sum+=i;
        System.out.println("Sum of first "+n+" odd numbers = "+sum);
        s.close();
    }
    
}
