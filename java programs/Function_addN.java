/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package function_addn;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Function_addN {

    /**
     * @param args the command line arguments
     */
    static int add(int n)
    {
        int i,sum=0;
        for(i=1;i<=n;i++)
            sum+=i;
        return sum;
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,sum;
        System.out.print("enter N = ");
        n=s.nextInt();
        sum=add(n);
        System.out.printf("Sum of first %d numbers = %d\n",n,sum);
        s.close();
    }
    
}