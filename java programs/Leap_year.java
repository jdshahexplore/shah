package leap_year;
import java.util.*;
public class Leap_year 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n;
        System.out.print("enter year = ");
        n=s.nextInt();
        if((n%4==0 && n%100!=0) || (n%400==0))
            System.out.println("Leap year");
        else
            System.out.println("Not a Leap year");    
    }
}
