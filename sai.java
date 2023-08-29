import java.util.ArrayList;
import java.util.Scanner;

class sai{
    public static int solve(ArrayList<Integer> a)
    {
        int count=1;

        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(a.get(i)==a.get(j))
                {
                    count++;
                    a.remove(j--);
                    i--;
                }    
            }
        }
        return count;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        ArrayList<Integer> a=new ArrayList<>();
        while(n-->0)
            a.add(sc.nextInt());
        System.out.println(solve(a));
    }
}