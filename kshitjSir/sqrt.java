package kshitjSir;

import java.util.Scanner;

class sqrt
{
    public static int pow(int exp)
    {
        int res=1;
        int base =2;
        while(exp>0)
        {
            if(exp%2==1)
                res*=base;
            base*=base;
            exp/=2;
        }

        return res;

    }

    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num= sc.nextInt();
        double exp=(Math.log10(num)/Math.log10(2)/2);
        System.out.println((int)Math.pow(2, exp));
    sc.close();}
}


/*


 pow(2,0.5*log2(N))



 */