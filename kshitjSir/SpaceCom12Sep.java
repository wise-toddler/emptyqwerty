
import java.util.ArrayList;
import java.util.Scanner;
class SpaceCom12Sep
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size");
        int n =sc.nextInt();
        int []arr = new int[n];
        System.out.println("Enter elements");
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        System.out.println("Enter size");
        n =sc.nextInt();
        int []arr2 = new int[n];
        System.out.println("Enter elements");
        for(int i=0;i<n;i++)
            arr2[i]=sc.nextInt();
        // System.out.println("Enter number of queries");
        // int q = sc.nextInt();
        // for(int i =0;i<q;i++)
        // {
        //     int a = sc.nextInt();
        //     System.out.println(find(arr,a));
        // }


        // System.out.println("printing distinct elements");
        // ArrayList<Integer> al = new ArrayList<>();
        // for(int i=0;i<n;i++)
        // {
        //     if(!find(al,arr[i]))
        //     {
        //         al.add(arr[i]);
        //         System.out.println(arr[i]);
        //     }
        // }
        printcomon(arr, arr2);

        

       
    sc.close();
    }
    static void printcomon(int[] a,int[] b)
    {
        for(int i =0;i<a.length;i++)
        {
            for (int j = 0; j < b.length; j++) 
            {
                if(a[i]==b[j])
                System.out.print(a[i]+" ");                   
            }
        }
    }
    static void printdictinct(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            int j;
            for(j=0;j<i;j++)
            {
                if(arr[i]==arr[j])
                    break;
            }
            if(i==j)
                System.out.println(arr[i]);
        }
    }
    static boolean find(ArrayList<Integer> al, int a) 
    {
        for(int i=0;i<al.size();i++)
        {
            if(al.get(i)==a)
                return true;
        }
        return false;
    }
    static boolean find(int[] arr, int a) 
    {
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==a)
                return true;
        }
        return false;
    }
}