/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package power;

/**
 *
 * @author shah jainam
 */
import java.util.Scanner;
public class Power 
{
    public static void main(String[] args) 
    {
        Scanner s=new Scanner(System.in);
        int i,y;
        double x,z=1;
        System.out.print("enter base and power = ");
        x=s.nextDouble();
        y=s.nextInt();
        for(i=1;i<=y;i++)
            z*=x;
        System.out.println(x + " raised to " + y + " is " + z);
        s.close();
    }
    
}
