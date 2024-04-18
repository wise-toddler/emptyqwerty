// package kshitjSir;
import java.util.*;
public class Sep29TowerofHanoi 
{
    // static void towerOfHanoi(int n, char A, char B, char C) 
    // {
    //     if (n == 1) {
    //         System.out.println("Move disk 1 from rod " + A + " to rod " + C); 
    //         return;
    //     }
    //     towerOfHanoi(n - 1, A, C, B); 
    //     System.out.println("Move disk " + n + " from rod " + A + " to rod " + C); 
    //     towerOfHanoi(n - 1, B, A, C); 
    // }
    // static void towerOfHanoi(int n, char A, char B, char C) 
    // {
    //     if(n==0) return;
    //     towerOfHanoi(n-1, A, C, B);
    //     System.out.println("Move disk "+n+" from rod "+A+" to rod "+C);
    //     towerOfHanoi(n-1, B, A, C);
    // }

    public static void toh(int n, int A, int B, int C, int i, ArrayList<ArrayList<Integer>> a)
    {
        if (n == 1) 
        {
            ArrayList<Integer> temp = new ArrayList<Integer>();
            temp.add(n);
            temp.add(A);
            temp.add(C);
            a.add(temp);
            return;
        }
        toh(n - 1, A, C, B, i, a);

        ArrayList<Integer> temp = new ArrayList<Integer>();
        temp.add(n);
        temp.add(A);
        temp.add(C);
        a.add(temp);

        toh(n - 1, B, A, C, i - 1, a);
    }

    public static  ArrayList<ArrayList<Integer>> towerOfHanoi(int A)
    {
        int n = A;
        int size = (int) Math.pow(2, n) - 1;
        // int a[][] = new int[size][3];
        ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>();
        toh(n, 1, 2, 3, size - 1, a);
        return a;
    }

    public static void main(String[] args) 
    {
        int n = 3;
        
        System.out.println(towerOfHanoi(n));
        // towerOfHanoi(n);
    }
}