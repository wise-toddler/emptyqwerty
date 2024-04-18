// package kshitjSir;


// import java.lang.reflect.Array;
import java.util.*;

// import kshitjSir.Arrays;


public class Oct3Sorting
{
    public static void nobelint(int[] arr) 
    {
        //sort array
        Arrays.sort(arr);
        int n = arr.length;
        for(int i = 0; i < n; i++)
        {
            if(arr[i]==i)
                System.out.println(arr[i]);
        }
        System.out.println("end");
    }
    public static void Bubblesort(int[] arr)
    {
        // int e=0;
        int n=arr.length;
        // for(int i =0;i<n-1;i++)
        // {
        //     int c=0;
        //     for(int j=0;j<n-i-1;j++)
        //     {
        //         System.out.println(++e);
        //         if(arr[j]>arr[j+1])
        //         {
        //             int temp=arr[j];
        //             arr[j]=arr[j+1];
        //             arr[j+1]=temp;  
        //             c++;
        //         }
        //     }
        //     if(c==0)
        //         break;
        // }
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;  
                }
                
            }
        }
            
            
    }
    public static void main(String[] args) 
    {
        // int[] arr = {2,1,4,3,5,6,7,8,9};
        // int[] arr = {1,2,3,4,5,6,7,8,9};
        // int[] arr = {9,8,7,6,5,4,3,2,1};
        // Bubblesort(arr);
        // System.out.println(Arrays.toString(arr));
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(3);
        arr.add(2);
        arr.add(4);
        arr.add(5);
        Collections.sort(arr);
        Collections.reverse(arr);
        System.out.println(arr);

    }   
}
