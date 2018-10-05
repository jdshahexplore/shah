package multiplication.table;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class MultiplicationTable 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n,i;
        System.out.print("enter number = ");
        n=s.nextInt();
        for(i=1;i<=10;i++)
        {
            System.out.printf("%d * %d = %d",n,i,n*i);
            System.out.println();
        }
        s.close();
    }    
}
