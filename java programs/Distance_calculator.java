package distance_calculator;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Distance_calculator 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int d_km,d_m,d_cm;
        double d_feet,d_inches;
        System.out.print("enter distance in km = ");
        d_km=s.nextInt();
        d_m=d_km*1000;
        d_cm=d_km*100000;
        d_feet=d_km*3280.84;
        d_inches=d_km*39370.1;
        System.out.printf("distance in metres = "+d_m+"\ndistance in centimetres = "+d_cm+"\ndistance in feet = "+d_feet+"\ndistance in inches = "+d_inches+"\n");
        s.close();
    }
}