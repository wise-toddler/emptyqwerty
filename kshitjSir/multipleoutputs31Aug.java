

import java.util.Scanner;

public class multipleoutputs31Aug
{
    public static coordinate findelement(int[][] a, int b)
    {
        coordinate cd=new coordinate();
        cd.cols=-1;
        cd.row=-1;
        for (int i = 0; i < a.length; i++) 
        {
            for (int j = 0; j < a[0].length; j++) 
            {
                if(a[i][j]==b)
                {
                    cd.row=i;
                    cd.cols=j;
                }
            }
        }
        return cd;
        
    }   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter rows space cols");
        int n=sc.nextInt();
        int m=sc.nextInt();
        int arr[][] =new int[n][m];
        System.out.println("enter "+m*n+" elements");
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                arr[i][j]=sc.nextInt();    
            }    
        }
        System.out.println("enter element to find");
        int b =sc.nextInt();
        System.out.println(findelement(arr, b).row + " " + findelement(arr, b).cols);
    sc.close();   
    }
}
class coordinate
    {
        int row;
        int cols;
    }