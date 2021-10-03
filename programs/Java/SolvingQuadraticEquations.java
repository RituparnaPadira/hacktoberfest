import java.io.*;
import java.math.*;

class Main
{
    public static void main(String[] args) throws Exception
    {
        int a,b,c,dis;
        float root1,root2;
       
        System.out.println("Enter values of a, b & c");
        DataInputStream sc = new DataInputStream(System.in);
        
        a=Integer.parseInt(sc.readLine());
        b=Integer.parseInt(sc.readLine());
        c=Integer.parseInt(sc.readLine());
        
        dis=(b*b)-(4*a*c);
        
        if (dis==0)
        {
            root1=root2=(float)(-b/(2*a));
            System.out.println("The roots are equal\nRoot one="+root1+"\nRoot two="+root2);
        }
        
        else if(dis>0)
        {
            root1=(float)(-b+Math.sqrt(dis))/(2*a);
            root2=(float)(-b-Math.sqrt(dis))/(2*a);
            System.out.println("The roots are real & distinct\n Root one="+root1+"\nRoot two="+root2);
        }
        
        else if(dis<0)
        {
            root1=(float)(-b/(2*a));
            root2=(float)(Math.sqrt(-dis)/(2*a));
            System.out.println("The roots are complex and imaginary\nRoot one="+root1+"+i"+root2+"\nRoot two="+root1+"-i"+root2);
        }
    }
}
