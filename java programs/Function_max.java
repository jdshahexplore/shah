/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package function_max;

/**
 *
 * @author shah jainam
 */
import java.util.*;
public class Function_max {

    /**
     * @param args the command line arguments
     */
    static int max(int a,int b,int c)
    {
        int max;
        max=a>b?(a>c?a:c):(b>c?b:c);
        return max;
    }
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner s=new Scanner(System.in);
        int a,b,c;
        System.out.print("enter three numbers = ");
        a=s.nextInt();
        b=s.nextInt();
        c=s.nextInt();
        System.out.printf("maximum of three numbers = %d\n",max(a,b,c));
        s.close();
    }
    
}
