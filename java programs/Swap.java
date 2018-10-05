package swap;
/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Swap 
{
    static void swap(int x,int y)
    {
        int temp;
        temp=x;
        x=y;
        y=temp;
        System.out.println("After Swapping x = "+x+" and y = "+y);
    }
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int x,y,temp;
        System.out.println("enter x and y = ");
        x=s.nextInt();
        y=s.nextInt();
        swap(x,y);
        s.close();
    }
    
}
