package conversion_day_to_month;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Conversion_day_to_month 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int day,month,n;
        System.out.print("enter no of days = ");
        n=s.nextInt();
        month=n/30;
        day=n%30;
        System.out.println("months = "+month);
        System.out.println("Days = "+day);
        s.close();
    }
}