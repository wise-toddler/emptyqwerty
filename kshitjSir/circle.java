package kshitjSir;

import java.util.Scanner;

/**
 * circle
 */
public class circle {

    

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n =sc.nextInt();
    for (int i = 0; i < 2*n; i++) {
        for (int j = 0; j < 2*n; j++) {
            System.out.print(Math.pow(i-n,2)+Math.pow(j-n,2)>=n*n?"  ":"* ");
        }System.out.println();
    }
sc.close();}
}