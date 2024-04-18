

public class Sep20optimization 
{
    public static int largestSubArray(int a[])
    {
        int sum = a[0];
        int max = a[0];
        for(int i =1;i<a.length;i++)
        {
            if(sum < 0)
                sum = 0;
            sum+=a[i];
            max = Math.max(max, sum);
        }
        return max;
    }
    public static void main(String[] args) 
    {
        System.out.println(largestSubArray(new int[]{2,5,-10,4,8,-1,5,-14,-20,0}));
    }   
}
