package kshitjSir;
import java.util.Scanner;

public class avg
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter size of array");
        int size=sc.nextInt();
        int[] ar=new int[size];
        for (int i = 0; i < size; i++) {
            ar[i]=sc.nextInt();
        }
        int sum=0;
        for (int i = 0; i < size; i++) {
            sum+=ar[i];
        }
        avg1(sum);
    sc.close();}


    public static void avg1(double s){
        System.out.println(s/10);

}
}
