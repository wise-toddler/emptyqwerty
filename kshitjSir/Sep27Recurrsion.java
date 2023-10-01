package kshitjSir;
public class Sep27Recurrsion 
{
    //fabonacci series
    public static int fab(int n)
    {
        if(n <= 1) return n;  // 0 1 1 2 3 5 8 13 21 34 55 89 144
        return fab(n-1)+fab(n-2);
    }
    //fabonacci series using loop
    public static int fabLoop(int n)
    {
        int a=0,b=1,c=0;
        for(int i=2;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return n<=1?n:c;
    }

    // sum of digits
    public static int sum(int n)
    {
        if(n==0) return 0;

        return n%10 + sum(n/10);
    }
    // print member of array using recurrsion
    public static void printArray(int a[],int n)
    {
        if(n==0)
            return;
        printArray(a,n-1);
        System.out.println(a[n-1]);
    }
    // check palindrome
    public static boolean isPal(String a, int i)
    {
        if(i>=a.length()-1-i)   return true;

        if(a.charAt(i)!=a.charAt(a.length()-1-i)) 
            return false;

        return isPal(a,i+1);
    }
    public static void main(String[] args) 
    {
        long st = System.currentTimeMillis();
        System.out.println(fabLoop(100));
        System.out.println(System.currentTimeMillis()-st);

        st=System.currentTimeMillis();
        System.out.println(fab(100));
        System.out.println(System.currentTimeMillis()-st);

    }
}