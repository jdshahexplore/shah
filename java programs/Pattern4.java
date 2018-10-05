/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pattern4;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Pattern4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,i,j;
        System.out.print("enter number of lines = ");
        n=s.nextInt();
        for(i=1;i<=n;i++)
        {
            if(i%2==1)
            {
                for(j=1;j<=i;j++)
                    System.out.print(j%2);
            }
            else
            {
                for(j=2;j<=(i+1);j++)
                    System.out.print(j%2);
            }
            System.out.println();
        }
        s.close();
    }
    
}
