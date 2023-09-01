// package kshitjSir;
import java.util.Scanner;

class String31Aug
{
    public static void sortLowerCaseString(String s)
    {
        int[] a =new int[26];
        for(int i =0;i<s.length();i++)
            a[s.charAt(i)-97]++;
        
        for(int i=0;i<26;i++)
            while(a[i]--!=0)
                System.out.print((char)(i+97));
    }
    public static void sortLowerCaseStringWithoutMakingNewArray(String s)
    {
        for(int i = 97;i<97+26;i++)
            for(int j =0;j<s.length();j++)
                if(s.charAt(j)==i)
                    System.out.print(s.charAt(j));
    }
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String s=sc.next();
        sortLowerCaseStringWithoutMakingNewArray(s);
    sc.close(); 
    }
}