import java.util.Scanner;

public class avg
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter size of array");
        int size=sc.nextInt();
        int[] ar=new int[sc];
        for (int i = 0; i < cs; i++) {
            ar[i]=sc.nextInt();
        }
        int sum=0;
        for (int i = 0; i < cs; i++) {
            sum+=ar[i];
        }
        avg(sum);
    }
    public static void avg(double s){
        System.out.println(s/10);

}
}
