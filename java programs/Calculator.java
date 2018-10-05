package calculator;
import java.util.*;
public class Calculator 
{
    static int add(int x,int y)
    {
        return x+y;
    }
    static int sub(int x,int y)
    {
        return x-y;
    }
    static int mul(int x,int y)
    {
        return x*y;
    }
    static int div(int x,int y)
    {
        return x/y;
    }
    static int mod(int x,int y)
    {
        return x%y;
    }
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int x,y,c,z;
        do
        {    
            System.out.print("enter your choice = ");
            c=s.nextInt();
            switch(c)
            {
                case 1:
                    System.out.print("enter x and y = ");
                    x=s.nextInt();
                    y=s.nextInt();
                    z=add(x,y);
                    System.out.println("result = "+z);
                    break;
                case 2:
                    System.out.print("enter x and y = ");
                    x=s.nextInt();
                    y=s.nextInt();
                    z=sub(x,y);
                    System.out.println("result = "+z);
                    break;
                case 3:
                    System.out.print("enter x and y = ");
                    x=s.nextInt();
                    y=s.nextInt();
                    z=mul(x,y);
                    System.out.println("result = "+z);
                    break;
                case 4:
                    System.out.print("enter x and y = ");
                    x=s.nextInt();
                    y=s.nextInt();
                    z=div(x,y);
                    System.out.println("result = "+z);
                    break;
                case 5:
                    System.out.print("enter x and y = ");
                    x=s.nextInt();
                    y=s.nextInt();
                    z=mod(x,y);
                    System.out.println("result = "+z);
                    break;
                case 6:
                    break;
                default:
                    System.out.println("wrong choice");
                    break;
            }
        }while(c!=6);
    }
}