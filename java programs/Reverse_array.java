/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reverse_array;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Reverse_array {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,i;
        System.out.print("enter total limit of array = ");
        n=s.nextInt();
        int[] a=new int[n];
        System.out.println("enter elements of array");
        for(i=0;i<n;i++)
            a[i]=s.nextInt();
        System.out.println("Reverse order of array");
        for(i=n-1;i>=0;i--)
            System.out.print(a[i]+"\t");
        s.close();
    }
    
}
