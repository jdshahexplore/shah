package series;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Series 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n,i;
        System.out.print("enter limit n = ");
        n=s.nextInt();
        System.out.print("1 +");
        for(i=2;i<=n;i++)
        {
            System.out.printf(" 1/%d ",i);
            if(i!=n)
                System.out.print("+");
        }
        s.close();
    }
    
}
