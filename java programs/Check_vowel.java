package check_vowel;
import java.util.*;
public class Check_vowel 
{
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        char c;
        System.out.print("enter an alphabet = ");
        c=s.next().charAt(0);
        switch(c)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                System.out.printf("entered character %c is a vowel\n",c);
                break;
            default:
                System.out.printf("entered character %c is not a vowel\n",c);
        }
        s.close();
    }
}
