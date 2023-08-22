package kshitjSir;

import java.util.Scanner;

class calculator
{
    static double sum(double a,double b){
        return a+b;
    }

    static double diff(double a,double b){
        return a-b;
    }

    static double prod(double a,double b){
        return a*b;
    }

    static double div(double a,double b){
        return a/b;
    }

    static double pow(double a,int b){
        int ret=1;
        for(;b>0;b--)
        ret*=a;
        return ret;
    }

    static int rem(int a,int b){
        return a%b;
    }
    
    static int base(int a,int base){
        int e =0,ans=0;
        do{
            int rem=a%base;
            ans+=(int)(rem*pow(10,e++));
            a/=base;
        }
        while (a!=0);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter 1st no");
        double a1=sc.nextInt();
        System.out.println("enter operator");
        char a=sc.next().charAt(0);
        System.out.println("enter 2nd no");
        double a2= sc.nextInt();
        switch (a) {
            case '+':sum(a1,a2);
                        break;
            case '-':diff(a1,a2);
                        break;
            case '*':prod(a1,a2);
                        break;
            case '/':div(a1,a2);
                        break;
            case '^':pow(a1,(int)a2);
                        break;
            case '%':rem((int)a1,(int)a2);
                        break;
            case 'b':System.out.println(base((int)a1,(int)a2));
                        break;
            default:
                break;
        }

    
    sc.close();}
}