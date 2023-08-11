//import java.lang.*;
import java.util.*;
class Digit_Queries
{
    public static String instring(int k)
    {  
        String prod ="";
        for(int i =1;i<=k;i++)
        prod=prod+i+"";
        return prod;

    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int k =sc.nextInt();

        String check=instring(k);
        //System.out.println(check+" "+check.length());
        int ans=(int)check.charAt(k-1)-48;


        int sum =0,num=0;
        int i =1;
        int pow=0;
        while(sum+i*9*Math.pow(10,pow)<k)
        {
            num+=9*Math.pow(10,pow);
            sum+=i*9*Math.pow(10,pow++);
            i++;
        }

        num+=(k-sum)/i;
        if((k-sum)%i!=0)
            num+=1; 
        int position=(k-sum)%(i);
        
        System.out.println(num+" "+i+" "+position);
        int fina;
        if(position==0)
            fina =num%10;
    
        else
            {
                position=i-position;
                fina =(int)(num/Math.pow(10,position))%10;
            }
        System.out.println(fina==ans);


                
    sc.close();}
}