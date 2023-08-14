package kshitjSir;

import java.util.Scanner;

class Arrays
{
    public static void firstandlast(int[] A,int target)
    {
        int first=0,last=A.length-1;
        while (first++<A.length)
            if(A[first-1]==target)
            {
                System.out.println(first-1);
                break;
            }
        while(last-->=0)
            if(A[last+1]==target)
            {
                System.out.println(last+1);
                break;
            }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("entter size");
        int n=sc.nextInt();
        int[] A= new int[n];
        for(int i=0;i<n;i++)
            A[i]=sc.nextInt();// intput array
        System.out.println("enter element to search");
        int target=sc.nextInt();
        firstandlast(A,target);
        
        
    sc.close();} 
}