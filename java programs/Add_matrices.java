/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package add_matrices;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Add_matrices {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int i,j,m,n;
        System.out.println("enter no. of row and column of matrix = ");
        m=s.nextInt();
        n=s.nextInt();
        int[][] a=new int[m][n];
        int[][] b=new int[m][n];
        int[][] c=new int[m][n];
        System.out.println("enter elements of First array = ");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                a[i][j]=s.nextInt();
        }
        System.out.println("enter elements of Second array = ");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                b[i][j]=s.nextInt();
        }
        System.out.println("Addition of two matrices");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                c[i][j]=a[i][j]+b[i][j];
                System.out.printf("%d\t",c[i][j]);
            }
            System.out.println();
        }
        s.close();
    }    
}