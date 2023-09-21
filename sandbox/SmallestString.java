package sandbox;
import java.util.Scanner;

public class SmallestString 
{
    public static int gcd(int a,int b){return ( a%b==0 ? b:gcd(b,a%b));}

    public static String rotString(String A, int B) 
    {
        String ans="";
        int n=A.length();
        int k=B%n;
        for(int i=n-k;i<n;i++)
            ans+=A.charAt(i);
        
        for(int i=0;i<n-k;i++)
            ans+=A.charAt(i);
        
        return ans;
    }

    public static String addString(String A, int C) 
    {
        String ans="";
        int n=A.length();
        for(int i=0;i<n;i++)
        {
            if(i%2==1)
                ans+=(char)(((A.charAt(i)-48+C)%10)+'0');
            else
                ans+=A.charAt(i);
        }
        return ans;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String A =sc.next(); 
        int n = A.length();
        int B= sc.nextInt(); 
        int C= sc.nextInt(); 
        // System.out.println(rotString(A,B));
        // int min =Integer.parseInt(A);
        String min = A,temp=A;
        
        for(int i =0;i<n/gcd(n,B);i++)
        {
            temp = rotString(min,i*B);
            if(min.compareTo(temp)>0)
                min = temp;
            for(int j=0;j<10;j++)
            {
                temp = addString(temp,C);
                if(min.compareTo(temp)>0)
                min = temp;
                System.out.println(i+" "+j+"  "+temp);
            }
        }
        
        System.out.println(min);
        sc.close();
    }
}
