package sandbox;


// import java.util.Arrays;

public class hi111 
{
    public int solve(int[] A, int B) 
    {
        int n = A.length;
        for(int i =1;i<A.length;i++)
            A[i]+=A[i-1];

        int max = A[B-1];

        for(int i=0;i<=B;i++)
        {
            max=Math.max(max,(A[n-1]-A[n-1-B+i]+((i>=1)?(A[i-1]):0)));
        }
        // while(i+j<=B)
        // {
        //     if(A[i]>A[n-1-j])
        //     {
        //         sum+=A[i];
        //         i++;
        //     }
        //     else if(A[i] == A[n-1-j])
        //     {
        //         sum+=A[i];
        //         i++;
        //         j++;
        //         B++;
        //     }
        //     else
        //     {
        //         sum+=A[n-1-j];
        //         j++;
        //     }
        // }
        return max;
    }

// 3 3 1 2 5  
// 3 6 7 9 14

    public static void main(String[] args) 
    {
        // System.out.println(Arrays.toString(solve(new int[]{1, 2, 3, 4, 5}, new int[][]{{1, 2}, {1, 3}, {1, 4}, {1, 5}})));
        int[] A = {5, 3, 1, 2, 3};
        int B = 5;
        int n = A.length;
        for(int i =1;i<A.length;i++)
            A[i]+=A[i-1];

        int max = A[B-1];

        for(int i=0;i<=B;i++)
        {
            max=Math.max(max,(A[n-1]-((B!=n)?(A[n-1-B+i]):0)+((i>=1)?(A[i-1]):0)));
        }
        System.out.println(max);
    }
}