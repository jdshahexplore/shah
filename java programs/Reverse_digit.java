/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reverse_digit;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Reverse_digit {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,rem,x=0;
        System.out.print("enter number = ");
        n=s.nextInt();
        while(n>0)
        {
            rem=n%10;
            x=x*10+rem;
            n=n/10;
        }
        System.out.println("reverse of entered number = "+x);
        s.close();
    }
}