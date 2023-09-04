class Solution {
public:
    long f(long n){return (n+n*n)/2;}

    int maxValue(int n, int i, int maxSum) 
    {
        maxSum-=n;
        long ans =0;
        long st=1,en=maxSum;
        while(st<=en)
        {
            long x=st+(en-st)/2;
            int k = ( 0 > x-i-1 ) ? 0 : x-i-1;
            int j = (0 > x+i-n) ? 0 : x+i-n;
            bool a=(x*x)-f(k)-f(j) <= maxSum;
            if(a)
            {
                ans=x;
                st=x+1;
            }
            else 
                en=x-1;
                
        }
        return ans+1;  
    }
};