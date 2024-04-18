// package kshitjSir;
class Sep15Optimization
{
    public static void rangeSumQueries(int[] A, int[][] queries)
    {
        for(int i=1;i<A.length;i++)
            A[i]=A[i-1]+A[i];
        for(int i =0;i<queries.length;i++)
            System.out.println(A[queries[i][1]]-((queries[i][0]-1)>=0?A[queries[i][0]-1]:0));        
    }

    public static void evencountquery(int[] A,int[][] queries)
    {
        A[0]=A[0]%2==0?1:0;
        for(int i=1;i<A.length;i++)
            A[i]=A[i-1]+((A[i]%2==0)?1:0);

        // for(int i=0;i<A.length;i++)
        //     System.out.print(A[i]+" ");
        for(int i =0;i<queries.length;i++)
            System.out.println(A[queries[i][1]]-((queries[i][0]-1)>=0?A[queries[i][0]-1]:0));   
    }
    public static int findEquilibriumIndex(int[] a) 
    {
        int n = a.length;
        int[] b= new int[n];
            b[0]=a[0];
        for(int i =1;i<n;i++)
            b[i]=b[i-1]+a[i];
        
        int[] c= new int[n];
        c[n-1]=a[n-1];
        for(int i =n-2;i>=0;i--)
            c[i]=c[i+1]+a[i];

        for(int i =0;i<n;i++)
            if(b[i]==c[i])
                return i;
        return -1;
}
    public static void main(String[] args) 
    {
        int[] A = {1,2,3,4,5,6,7,8,9,10};
        // int[][] queries = {
        //                     {0,4},
        //                     {1,3},
        //                     {2,4},
        //                     {3,3},
        //                     {4,4}
        //                 };
        findEquilibriumIndex(A);
    }
}