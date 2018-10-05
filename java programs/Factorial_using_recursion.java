/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package factorial_using_recursion;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Factorial_using_recursion {

    /**
     * @param args the command line arguments
     */
    static int fact(int n)
    {
        if(n==0)
            return 1;
        else
            return(n*fact(n-1));
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n;
        System.out.print("enter n = ");
        n=s.nextInt();
        if(n<0)
            System.out.print("entered number is invalid\n");
        else
            System.out.printf("Factorial of %d = %d\n",n,fact(n));
        s.close();
    }
    
}
