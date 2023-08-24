package kshitjSir;
import java.util.Scanner;

class String24
{
    public static int countVowel(String a)
    {
        int count=0;
        for(int i=0;i<a.length();i++)
        {
            
            char q =a.charAt(i);
            if(q=='a' || q=='e' || q=='i' || q=='o' || q=='u')
            count++;
        }
        return count;
    }
    // this method won't work because string is non mutable
    // public static String rev(String s)
    // {
    //     for(int i=0;i<s.length()/2;i++)
    //     {
    //         char temp=s.charAt(i);
    //         s.charAt(i)=s.charAt(s.length()-1-i);
    //         s.charAt(s.length()-1-i)=s.charAt(i);
    //     }
    //     return s;
    // }


    public static boolean isPalindrome(String s)
    {
        int n =s.length();
        for(int i =0;i<n/2;i++)
        {
            if(s.charAt(i)!=s.charAt(n-i-1))
                return false;
        }

        return true;
    } 
    public static boolean hasUpperCase(String s)
    {
        for(int i =0;i<s.length();i++)
            if('A' <= s.charAt(i) && s.charAt(i)<= 'Z')
                return true;
            return false;
    }
    public static boolean hasLowerCase(String s)
    {
        for(int i =0;i<s.length();i++)
            if('a' <= s.charAt(i) && s.charAt(i)<= 'z')
                return true;
            return false;
    }
    public static boolean hasNumber(String s)
    {
        for(int i =0;i<s.length();i++)
            if('0' <= s.charAt(i) && s.charAt(i)<= '9')
                return true;
            return false;
    }
    public static boolean hasSpecialChars(String s)
    {
        for(int i =0;i<s.length();i++)
            if(s.charAt(i)=='!'|| s.charAt(i) == '@' || s.charAt(i)=='$' || s.charAt(i)=='%'||s.charAt(i)=='^'||s.charAt(i)=='&')
                return true;
            return false;
    }
    public static String passStrength(String s)
    {
        int count=0;
        if(s.length()>=8)
            {
                if(hasUpperCase(s)) count++;
                if(hasLowerCase(s)) count++;
                if(hasNumber(s)) count++;
                if(hasSpecialChars(s)) count++;
            }
        else return "minimum 8 chars";
        switch (count)
        {
            case 1 : return "poor";
            case 2 : return "weak";
            case 3 : return "moderate";
            case 4 : return "Strong";
            default : return "invalid"; 
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(passStrength(sc.next()));
    sc.close();
    }
}