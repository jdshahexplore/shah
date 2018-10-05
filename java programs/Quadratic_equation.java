package quadratic_equation;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Quadratic_equation 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int a,b,c;
        double D,x1,x2;
        System.out.println("enter coefficients of Quadratic equation of form ax^2+bx+c");
        System.out.printf("enter a = ");
        a=s.nextInt();
        System.out.printf("enter b = ");
        b=s.nextInt();
        System.out.printf("enter c = ");
        c=s.nextInt();
        D=(b*b)-(4*a*c);
        if(D<0)
            System.out.println("Roots are imaginary");
        else
        {
            x1=((-b)+Math.sqrt(D))/(2*a);
            x2=((-b)-Math.sqrt(D))/(2*a);
            if(D==0)
            {
                System.out.println("Roots are Equal");
                System.out.println("x1 = "+x1+"\nx2 = "+x2);
            }
            else
            {
                System.out.println("Roots are distinct");
                System.out.println("x1 = "+x1+"\nx2 = "+x2);
            }
        }
    }
    
}