// package kshitjSir;

//import java.util.Scanner;

class Array21Aug
{
    public static void printArray(int[][] ar)
    {
        for(int i =0;i<ar.length;i++)
        {
            for(int j =0;j<ar[i].length;j++)
            
            System.out.print(ar[i][j]+" ");
            
            System.out.println();
        }
        
    }



    public static void arrMul()
    {
        int a=4;
        int b=3; 
        int c=2;
        int [][]arrA={
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        int [][]arrB={
            {1,2},
            {3,4},
            {5,6}
        };

        int [][]arrmul=new int [a][c];
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<c;j++)
            {
                int sum =0;
                for(int k=0;k<b;k++)
                    sum+=arrA[i][k]*arrB[k][j];
                arrmul[i][j]=sum;
            }
        }
        printArray(arrmul);
    }



    public static int det(int[][] m)
    {
        int n=m.length;
        int det=0;
        for(int i =0;i<n;i++)
        {
            int d1=1,d2=1;
            for(int j=i,k=0;k<n;j++,k++)
            {
                int x=k;
                int y=j%n;
                d1*=m[x][y];
                d2*=m[x][n-1-y];
            }
            det+=d1-d2;
        }
        return det;
    }
    public static int det2(int [][]a)
    {
        int n =a.length;
        int det=0;
        if(n==1)
            return a[0][0];
        if (n == 2)
            return a[0][0] * a[1][1] - a[0][1] * a[1][0];
        for(int i=0;i<n;i++)
        {
            int [][]ar=new int[n-1][n-1];
            for(int t=0;t<n-1;t++)
            {
                for(int k=1,j=i+1;k<n;j++,k++)
                    ar[t][k-1]=a[t+1][j%n];
            }
            // printArray(ar);
            // System.out.println();
            det+=a[0][i]*det2(ar);
        }
        return det;
        
    }

    public static void main(String[] args) {
         int [][]arr={
            {15,10,11},
            {12,14,16},
            {32,4,12}
        };
        System.out.println(det2(arr));
        System.out.println(det(arr));
    };

}
