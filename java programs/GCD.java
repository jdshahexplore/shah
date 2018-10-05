package gcd;
import java.util.*;
public class GCD 
{
    static int gcd(int n1,int n2)
    {
        int rem;
        while(n1%n2!=0)
        {
            rem=n1%n2;
            n1=n2;
            n2=rem;
        }
        return n2;
    }
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n1,n2,result;
        System.out.print("enter two numbers = ");
        n1=s.nextInt();
        n2=s.nextInt();
        if(n1>n2)
            result=gcd(n1,n2);
        else
            result=gcd(n2,n1);
        System.out.printf("GCD of %d and %d = %d\n",n1,n2,result);
        s.close();
    }
}
