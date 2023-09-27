// https://www.codechef.com/START102D/problems/STOCKMARKET
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
        int n;cin>>n;
        vi a(n);
        int mina=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            sum+=a[i];
            mina = min(mina,a[i]);
        }
        cout<<(sum-mina)<<endl;
    }
}