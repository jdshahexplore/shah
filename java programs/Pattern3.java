/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pattern3;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Pattern3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,i,j;
        System.out.print("enter number of lines = ");
        n=s.nextInt();
        for(i=65;i<=(64+n);i++)
        {
            for(j=(64+n);j>=i;j--)
                System.out.print((char)i);
            System.out.println();
        }
        s.close();
    }
    
}
