/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fibonacci;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Fibonacci {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,a=0,b=0,c=1,i=1;
        System.out.print("enter n = ");
        n=s.nextInt();
        while(i<=n)
        {
            System.out.print(c+"\t");
            a=b;
            b=c;
            c=a+b;
            i+=1;
        }
        s.close();
    }    
}