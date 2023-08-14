package kshitjSir;

import java.util.Scanner;

class countnotmax 
{
    public static int max(int a[])
    {
        int max=a[0];
        for(int i =0;i<a.length;i++)
        {
            if(max<a[i])
            max=a[i];
        }
        return max;
        
    }
    public static int lessthanmax(int a[]) {
        
        int count=0;
        int max=max(a);
        for(int i =0;i<a.length;i++)
            if(max==a[i])
            count++;
        return a.length-count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter size");
        int n=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
        System.out.println(lessthanmax(a));



    sc.close();}
}