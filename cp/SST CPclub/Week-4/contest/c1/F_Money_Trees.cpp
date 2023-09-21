// https://codeforces.com/contest/1873/problem/D
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
        int n,k;cin >> n >> k;
        vi a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vi b(n);
        for(int i=0;i<n;i++) cin >> b[i];

        int totalfruits = 0;
        int l=0,r=0;
        int anslength = -1;
        while(r<n)
        {
            totalfruits+=a[r];
            while(l<r and (totalfruits>k or (r>0 and b[r-1]%b[r]!=0)))
            {
                totalfruits-=a[l];
                l++;
            }
            if(totalfruits<=k)
            {
                anslength = max(anslength,r-l+1);
            }

            r++;
        }
        cout << max(0LL,anslength) << endl;
             
    }
}