/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sort_asc;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Sort_asc {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int n,i,j,temp;
        System.out.print("enter number of elements you want to sort = ");
        n=s.nextInt();
        int[] a=new int[n];
        System.out.println("enter elements = ");
        for(i=0;i<n;i++)
            a[i]=s.nextInt();
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        System.out.println("Elements in ascending order");
        for(i=0;i<n;i++)
            System.out.print(a[i]+"\t");
        s.close();
    }
    
}
