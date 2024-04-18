
import java.util.Scanner;
/*
4
1 2 3 4 17 18 19 20 
  5 6 7 14 15 16 
    8 9 12 13 
      10 11 
 */
class pattern
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int k=1,m;
        for(int i=1;i<=n;i++)
        {   
            m=(2*n*n+4*n-2*n*i-3*i+i*i+2)/2-n+i;
            for(int j=1;j<i;j++)System.out.print("  ");
            for(int j=1;j<=n-i+1;j++)System.out.print(k+++" ");
            //System.out.print("   ");
            for(int j=1;j<=n-i+1;j++)System.out.print(m+++" ");
            System.out.println();
        }


    sc.close();}
}