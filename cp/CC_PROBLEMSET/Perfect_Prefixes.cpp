// https://www.codechef.com/START141B/problems/PREPER
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
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;

    // a.resize(n);cin >> a;
    // int sum=0;
    // int perfectsum=0;
    // vi should(n,0);
    // fo1(i,0,n/2*2,2)
    // {
    //     // without swap 
    //     sum+=a[i];
    //     perfectsum+=i+1;
    //     if(sum==perfectsum) should[i]=1,should[i+1]=1;
    //     sum+=a[i+1];
    //     perfectsum+=i+2;
    //     if(should[i]==0 and (sum==perfectsum)) should[i+1]=2,should[i]=2;
    //     if(should[i]==0)
    //     {
    //         sum-=a[i]+a[i+1];
    //         perfectsum-=(i+1)+(i+2);
    //         sum+=a[i+1];
    //         perfectsum+=i+1;
    //         if(sum==perfectsum) should[i+1]=3,should[i]=3;
    //         sum+=a[i];
    //         perfectsum+=i+2;
    //         if(should[i]==0 and sum==perfectsum) should[i]=4,should[i+1]=4;
    //     }
    // }
    // cout << should << endl;

    vi mex(n+1,0);
    mex[0]=1;
    vi perm(n,0);
    set<int> s;
    fo1(i,0,n,1)
    {
        s.insert(a[i]);
        mex[i+1]=mex[i];
        while(s.count(mex[i+1])) mex[i+1]++;
        if(mex[i+1]==i+2) perm[i]=1;
    }
    deb(perm)
    // perm is kon kon se alredy perfect prefix hai
    deb(mex)
    vi sum(n+1,0);
    fon_(i,n)
    {
        sum[i]=sum[i+1]+perm[i];
    }
    deb(sum)

    int ans=sum[0]; 
    vi best(2,0);
    int cnt=0;
    int maxi=0;
    fo1(i,1,n,1)
    {
        cout << "i: " << i << " best: " << best << " cnt: " << cnt << " maxi: " << maxi << endl;
        if(maxi<=i)
        {
            if(perm[i-1])
            {
                best[i%2]=max(best[i%2],cnt+perm[i-1])+perm[i];
            }
            else
            {
                best[i%2]=max(best[i%2],cnt)+perm[i];
                best[i%2]+=(mex[i-1]==a[i]);
            }
        }
        else
        {
            best[i%2]=max(best[i%2]+perm[i],cnt+perm[i]);
        }
        ans=max(ans,best[i%2]+sum[i+1]);
        cnt+=perm[i-1];
        maxi=max(maxi,a[i-1]);
    }
    cout << ans << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}