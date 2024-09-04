// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-2.md
// https://cses.fi/problemset/task/1071
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long r;cin >> r;
        long long c;cin >> c;
        long long n=max(r,c);
        long long ans;
        if(n%2==0)
        {
            if(r>=c)
                ans=n*n+1-(r+c-n);
            else 
                ans=(n-1)*(n-1)+(r+c-n);                
        }
        else
        {
            if(r<=c)
                ans=n*n+1-(r+c-n);
            else 
                ans=(n-1)*(n-1)+(r+c-n); 
        }
        cout << ans << endl; 
        // logic cc goes to satish
        
        // if(n%2==0)
        // {
        //     ans = r>=c ? (n*n-n+1)-(n-r):(n*n-n+1)+(n-c);
        //     cout << ans << endl; 
        // }
        // else 
        // {
        //     ans = r>=c ? (n*n-n+1)-(n-c):(n*n-n+1)+(n-r);
        //     cout << ans << endl; 
        // }  
    }
}