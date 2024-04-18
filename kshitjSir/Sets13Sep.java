

import java.util.HashMap;
// import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Sets13Sep 
{
    static boolean find(int[] arr,int a)
    {
        HashSet<Integer> hs = new HashSet<>();
        for(int i=0;i<arr.length;i++)
        {
            if(hs.contains(a-arr[i]))
                return true;
            
            hs.add(arr[i]);
        }
        return false;
    }
    public static void printoddfreq(int[] arr)
    {
        HashSet<Integer> hs = new HashSet<>();
        for(int i=0;i<arr.length;i++)
        {
            if(hs.contains(arr[i]))
                hs.remove(arr[i]);
            
            else 
                hs.add(arr[i]);
        }
        for(int i : hs)
        {
            System.out.println(i);
        }
    }
    public static void hashMaptry(int[] arr) // print frequency of each element
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i=0;i<arr.length;i++)
        {
            if(hm.containsKey(arr[i]))
            {
                int freq = hm.get(arr[i]);
                hm.put(arr[i], freq+1);
            }
            else
                hm.put(arr[i], 1);
        }
        hm.forEach((k,v)->System.out.println(k+" "+v));
    }

    public static int firstReapeatingElement(int[] arr)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i=0;i<arr.length;i++)
        {
            if(hm.containsKey(arr[i]))
            {
                int freq=hm.get(arr[i]);
                hm.put(arr[i], freq+1);
            }
            else
                hm.put(arr[i],1);
        }
        int q=-1;
        // iterator
        // for(ma
        // hm.forEach((k,v) -> {
        //     if(v>1) 
        //     {
        //         q=k;
        //         // break;
        //     }

        // });
        return q;

        

    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size");
        int n =sc.nextInt();
        int []arr = new int[n];
        System.out.println("Enter elements");
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        // System.out.println("enter sum");
        // int sum = sc.nextInt();
        hashMaptry(arr);
        sc.close();
    }
    
}