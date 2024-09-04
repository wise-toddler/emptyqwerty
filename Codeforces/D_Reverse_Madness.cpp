// https://codeforces.com/contest/1878/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
// largest smallest or equal binary search
int binSear(vi &a,int x)
{
    int st = 0;
    int en = a.size()-1;
    int ans = -1;
    while(st<=en)
    {
        int mid = st+(en-st)/2;
        if(a[mid]<=x)
        {
            ans = mid;
            st = mid+1;
        }
        else
            en = mid-1;
    }
    return ans;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        // nl nl
        int n,k;cin >> n >> k;
        string s;cin >> s;
        string ans=s;
         
        vi l(k),r(k);cin >> l >> r;
        vi mir(n);
        int kk=0;
        fon(i,k) fo1(j,l[i]-1,r[i],1) mir[j]=r[i]-j-1+l[i]-1;
        
        int q;cin >> q;
        vi seq(n,0);
        while(q--)
        {
            int x;cin >> x;
            int index = binSear(l,x);
            int a = min(x,l[index]+r[index]-x);
            int b = max(x,l[index]+r[index]-x);
            a--,b--;
            // deb(a) deb(b)
            if(a==b) continue;
            seq[a]++;
            if(b+1<n) seq[b+1]--;
        }
        for(int i=1;i<n;i++)
            seq[i]+=seq[i-1];
        for(int i=0;i<n;i++)
        {
            if(seq[i]%2)
            {
                swap(ans[i],ans[mir[i]]);
                seq[i]=seq[mir[i]]=0;
            }
        }
        cout << ans << endl;
    }
}