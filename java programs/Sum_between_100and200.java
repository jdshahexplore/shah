package sum_between_100and200;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Sum_between_100and200 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int i;
        for(i=101;i<200;i++)
        {
            if(i%5==0)
                System.out.printf("%d\t",i);
        }
        s.close();
    }
}