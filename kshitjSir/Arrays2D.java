package kshitjSir;

import java.util.Scanner;

class Arrays2D
{
    public static int maxEle(int[][] a)
    {
        int max =a[0][0];
        for(int i=0;i<a.length;i++)
            for(int j=0;j<a[0].length;j++)
                if (max<a[i][j])
                    max=a[i][j];
        return max;
    }
    public static int summ(int[][] a)
    {
        int sum=0;
        for(int i=0;i<a.length;i++)
            for(int j =0;j<a[0].length;j++)
                sum+=a[i][j];
        return sum;
    }
    public static int maxSumRow(int[][] a)
    {
        int maxRow=0,maxRowKaSumm=0;
        for(int i =0;i<a.length;i++)
        {
            int sum=0;
            for(int j =0;j<a[0].length;j++)
                sum+=a[i][j];
            if(sum>maxRowKaSumm)
                {
                    maxRowKaSumm=sum;
                    maxRow=i;
                }


        }
        return maxRow;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter rows");
        int n = sc.nextInt();
        System.out.println("enter cols");
        int m =sc.nextInt();
        System.out.println("enter "+m*n+" elements");
        int a[][]=new int[n][m];
        for(int i =0;i<n;i++)
            for(int j =0;j<m;j++)
                a[i][j]=sc.nextInt();
        System.out.println(maxSumRow(a));
    sc.close();}
    
}