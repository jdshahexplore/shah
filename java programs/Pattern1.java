package pattern1;
import java.util.*;
public class Pattern1 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n,i,j;
        System.out.print("enter number of lines = ");
        n=s.nextInt();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                System.out.print("#");
            System.out.println();
        }
        s.close();
    }
}
