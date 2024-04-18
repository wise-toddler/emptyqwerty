// package kshitjSir;
class Arrays22Ayg
{
    public static void printarr(int a[][])
    {
        for(int i=0;i<a.length;i++)
        {
            for(int j=0;j<a[0].length;j++)
                System.out.print(a[i][j]+" ");
                System.out.println();
        }
    }

    public static void printd1(int [][]a)
    {
        int n =a.length;
        for(int i=0;i<n;i++)
            System.out.print(a[i][i]+" ");
            System.out.println();
    }

    public static void printd2(int a[][])
    {
        int n= a.length;
        for(int i=0;i<a.length;i++)
            System.out.print(a[i][n-1-i]+" ");
            System.out.println();
    }

    public static void transpose(int [][]a)
    {
        int n=a.length;
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
            {
                int temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        printarr(a);
    }

    public static void main(String[] args) {
        int ar[][]={
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        transpose(ar);
    }
}