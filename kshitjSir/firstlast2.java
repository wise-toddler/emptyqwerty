package kshitjSir;

import java.util.Scanner;

class firstandlast2 {
    public static int firstTarget(int a[], int target) {
        int st = 0, en = a.length - 1, ans = -1;
        while (st <= en) {
            int mid = (st + en) / 2;
            if (a[mid] == target) {
                ans = mid;
                en = mid - 1;
            } else if (a[mid] > target)
                en = mid - 1;
            else
                st = mid + 1;

        }
        return ans != -1 ? ans : -1;
    }

    public static int lastTarget(int a[], int target) {
        int st = 0, en = a.length - 1, ans = -1;
        while (st <= en) {
            int mid = (st + en) / 2;
            if (a[mid] == target) {
                ans = mid;
                st = mid + 1;
            } else if (a[mid] > target)
                en = mid - 1;
            else
                st = mid + 1;

        }
        return ans != -1 ? ans : -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter size");
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        System.out.println("enter target");
        int target = sc.nextInt();
        System.out.println(firstTarget(a, target) + " " + lastTarget(a, target));
        sc.close();
    }
}