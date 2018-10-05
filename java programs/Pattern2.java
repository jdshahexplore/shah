/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pattern2;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Pattern2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,i,j,k;
        System.out.print("enter number of lines = ");
        n=s.nextInt();
        for(i=1;i<=n;i++)
        {
            for(k=1;k<i;k++)
                System.out.print(" ");
            for(j=i;j<=n;j++)
                System.out.print(j);
            System.out.println();
        }
        s.close();
    }
}
