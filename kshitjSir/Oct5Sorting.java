package kshitjSir;
import java.util.Arrays;

public class Oct5Sorting 
{

    public static void merge2sortedsubarrays(int[] arr, int l, int m, int r) 
    {
        int i = l;
        int j = m + 1;
        for (int k = l; k <= r; k++) 
        {
            if (j <= r && arr[i] >= arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                // j--;
            } 
            else 
            {
                j++;
            }
        }
    }
    // public static int  InversionCountinArray(int[] arr)
    // {
    //     int count = 0;
    //     int n = arr.length;
    //     // for(int i=n-1;i>=0;i--)
    //     // {
    //     //     for(int j=i-1;j>=0;j--)
    //     //     {
    //     //         if(arr[i]<arr[j])
    //     //         {
    //     //             count++;
    //     //         }
    //     //     }
    //     // }// O(n^2) brute force
    //     // binary search
    //     for(int i=0;i<n;i++)
    //     {
    //         int l = i+1;
    //         int r = n-1;
    //         while(l<=r)
    //         {
    //             int m = (l+r)/2;
    //             if(arr[i]>arr[m])
    //             {
    //                 count++;
    //                 l = m+1;
    //             }
    //             else
    //             {
    //                 r = m-1;
    //             }
    //         }
    //     }
    // }
    public static void main(String[] args) 
    {
        int a[] = {1,4,3,5,5,7,2,3,4,1};
        merge2sortedsubarrays(a, 2, 5, 8);        
        System.out.println(Arrays.toString(a));
        
    }
}
// 1 4 | 3 5 5 7 | | 2 3 4| 1


// 1 4 | 2 3 3 4     5 5 7| 1


// l= 2,m= 5,r = 8