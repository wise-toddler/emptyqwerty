// https://www.codechef.com/problems/SANTACHOC
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << endl;
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
        int n,k;cin >> n >> k;
        vi a(n);
        for(int &i : a) cin >> i;
        sort(all(a));
        int sum = 0;
        for(int i=0;i<n;i++) 
            sum += a[i];
        // debug(sum)
        if(k==0 && sum!=0)
        {
            if(sum%n==0) 
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
            continue;
        }
        if(sum>=n)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;

    }
}