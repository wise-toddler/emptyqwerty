package kshitjSir;
class optimization14Sep
{
    public static int abeforeg(String A)
    {
        int a=0,g=0;
        for (int i=0;i<A.length();i++)
        {
            if(A.charAt(i)=='a')
                a++;
            if(A.charAt(i)=='g')
                g+=a;
        }
        return g;

        // sir's approach
        // for (int i=A.length()-1;i>=0;i--)
        // {
        //     if(A.charAt(i)=='g')
        //         g++;
        //     if(A.charAt(i)=='a')
        //         a+=g;
        // }
        // return a;
    }
    
    public static int leaderelements(int ...A)
    {
        int ans=0;
        int max=Integer.MIN_VALUE;
        for (int i = 0; i < A.length-1; i++) 
        {
            if(A[i]>max)
            {
                ans++;
                max=A[i];
            }
        }
        return  ans;
    }

    public static int toggleSwitch(String a)
    {
        int ans=0;
        for(int i =1; i< a.length();i++)
        {
            if(a.charAt(i-1)!=a.charAt(i))
            ans++;
        }
        if(a.charAt(0)=='0')
            ans++;
        return ans;
    }
    public static void main(String[] args) 
    {
        System.out.println(leaderelements(1,34,4,54,6,56,77,8,65,69));
    }
}