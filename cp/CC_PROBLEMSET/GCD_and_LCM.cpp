// https://www.codechef.com/problems/GCDLM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int x,y,k;cin >> x >> y >> k;
        int a = max(x,y);
        int b = min(x,y);
        while(k--)
        {
            a = __gcd(a,b);
            if(b>a) 
                swap(a,b);
            if(a==b || (b==1 && (k==0 || a==1)))
            {
                cout << (a+b) <<endl;
                break;
            }
        }
        if(a!=b && b!=1)    
            cout << (a+b) << endl;
    }
}