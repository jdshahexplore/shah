package refactorable_number;
import java.util.*;
class Refactorable_number 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int x,i,j;
        //enter limit x
        x=s.nextInt();
        int[] c=new int[x];
        for(i=0;i<x;i++)
            c[i]=0;
        for(i=1;i<=x;i++)
        {
            for(j=1;j<=i;j++)
            {
                if(i%j==0)
                    c[i-1]++;
            }
        }
        System.out.println("refactorable numbers are");
        for(i=1;i<=x;i++)
        {
            if(i%c[i-1]==0)
                System.out.print(i+"\t");
        }
        s.close();
    }
}
