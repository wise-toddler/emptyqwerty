// https://codeforces.com/contest/1878/problem/E
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
int pow(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a;
        a *= a;
        b >>= 1;
    }    
    return ans;
}
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        // cout << i << ' ';
        print(v[i]);
    }
}

int good(vii &bits,vi &a,int l,int k)
{

    int ans = 0;
    int st= l;
    int en = a.size()-1;
    while(st<=en)
    {
        int mid = (st+en)/2;
        int andd = 0;
        for(int i=0;i<32;i++)
        {
            int cnt = bits[mid][i] - (l==0?0:bits[l-1][i]);
            if(cnt == mid-l+1)
            {
                andd += (1 << i);
            }
        }

        if(andd >= k)
        {
            ans = mid;
            st = mid+1;
        }
        else
            en = mid-1;
    }
    return ans + 1;
}
signed main()
{
    IOS
    int t;
    cin >> t;
    // t=1;
    while(t--)
    {
        int n;cin >> n;
        vi a(n);
        // vi a = {15,14,17,42,34};
        for(int i=0;i<n;i++)cin >> a[i];
        
        vii bits(n,vi(32,0));
        for(int i=0;i<n;i++)
        {
            int x = a[i];
            for(int j=0;j<32;j++)
                bits[i][j] = (x&(1 << j)) ? 1 : 0;
        }
        // print(bits);

        for(int j=0;j<32;j++)
        {
            for(int i =1;i<n;i++)
            {
                bits[i][j] += bits[i-1][j];
            }
        }
        // print(bits);

        int q;cin >> q;
        while(q--)
        {
            int l,k;cin >> l >> k;
            // int l = 4;
            // int k = 5;
            l--;
            if(a[l] < k) 
            {
                cout << -1 << ' ';
                continue;
                // return 0;
            }
            cout << good(bits,a,l,k) << ' ';
        }
        cout << endl;
    }
}
/*

b[i][j] & a;
    a<<1;

*/