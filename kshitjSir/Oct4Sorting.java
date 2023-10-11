package kshitjSir;
import java.util.Arrays;

public class Oct4Sorting 
{
    public static int kthMin(int[] arr, int k)
    {
        for(int i =0;i<k;i++)
        {
            for(int j=i+1;j<arr.length;j++)
            {
                if(arr[i]>arr[j])
                {
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;  
                }
            }
        }
        return arr[k-1];
    }
    public static void insertionSort(int []arr)
    {
        int n=arr.length;
        for(int i=1;i<n;i++)
        {
            int key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }
    public static void main(String[] args) 
    {
        int []arr={5,4,3,2,1};
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
