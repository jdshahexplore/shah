package fibonacci_recursion;
import java.util.*;
public class Fibonacci_recursion 
{
    static int fibonacci(int n)
    {
        if(n==1)
            return 1;
        else if(n==2)
            return 1;
        else
            return fibonacci(n-1)+fibonacci(n-2);
    }
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int n,i,j;
        System.out.print("enter limit = ");
        n=s.nextInt();
        for(i=1;i<=n;i++)
        {
            j=fibonacci(i);
            System.out.print(j+"\t");
        }
        s.close();
    }
}
