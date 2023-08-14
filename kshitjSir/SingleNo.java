package kshitjSir;

import java.util.Scanner;

class SingleNo
{    
    public static int single(int a[])
    {
        int n=a.length;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j =0;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    count++;
                    if(count ==2)
                    break;
                }
            }
            if(count==1)
            return a[i];
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("entter size");
        int n=sc.nextInt();
        int[] A= new int[n];
        for(int i=0;i<n;i++)
            A[i]=sc.nextInt();// intput array
        System.out.println(single(A));
        
     
    sc.close();}
}
