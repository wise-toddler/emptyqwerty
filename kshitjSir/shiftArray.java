package kshitjSir;

import java.util.Scanner;

class shiftArray
{
//    public static void rightShift(int a[]) {

//             int temp=a[a.length-1];
//             for(int i =1;i<a.length;i++)
//             a[a.length-i]=a[a.length-i-1];
//             a[0]=temp;
    
//     }
    public static void revArr(int a[],int st, int en) 
    {
        for(int i =st,j=en-1;i<(st+en)/2;i++,j--)
        {
            int temp =a[i];
            a[i]=a[j];
            a[j]=temp;
        }   
    }



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("size of Array");
        int n= sc.nextInt();
        int a[]=new int[n];
        System.out.println("enter "+n+" nos:");
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        System.out.println("enter k:");
        int k = sc.nextInt();
        k%=n;
        revArr(a,0,n);
        revArr(a, 0, k);
        revArr(a, k, n);
            for(int i =0;i<n;i++)
                System.out.print(a[i]+" ");
                System.out.println();
        System.out.println();        
    sc.close();}
}