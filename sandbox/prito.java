package sandbox;
import java.util.*;
class prito
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m =sc.nextInt();
        int arr[][] = new int[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j]=sc.nextInt();
            }
        }
        for(int i =m-1;i>=0;i--)
        {
            int a=0;
            while(i+a<m && a<n)
            {
                System.out.print(arr[a][a+i]+" ");
                a++;
            }
     
        }
        for(int i=1;i<n;i++)
        {
            int a=0;
            while(i+a<n && a<m)
            {
                System.out.print(arr[i+a][a]+" ");
                a++;
            }
        }
        
    sc.close();}
}