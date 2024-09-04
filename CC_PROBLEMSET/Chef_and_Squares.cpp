// https://www.codechef.com/LRNDSA05/problems/CHEFSQRS?tab=statement
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int solve(int n)
{
    // int n;//cin >> n;
    int a=-1;
    for(int i=1;i*i<=n;i++)
        if(n%i==0 && !(((n/i)&1)^(i&1)) && ((n/i)!=i))
            a=(n/i-i)/2*(n/i-i)/2;
    return a;
}
signed main()
{
	// your code goes here
    int t;cin >> t;
    // for(int i=2;i<=t;i+=2)
    int i=t;
    // while(t--)
    {
        int a=solve(i);
            cout<< i <<" : " << a << '\n';
    }
}