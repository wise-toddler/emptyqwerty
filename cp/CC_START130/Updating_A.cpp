// https://www.codechef.com/START130B/problems/UPDA
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}

int f(vi a)
{
    int n=a.size();
    if(n==1) return a[0];
    int sum=0;
    int minsum=min({a[0]+a[1],a[n-1]+a[n-2],0LL});
    int cursum=a[0]+a[1];
    int i=0;
    for(int j=2;j<n;j++)
    {
        cursum+=a[j];
        while(i<j-1 and (cursum>=0 || a[i]>=0))
        {
            cursum-=a[i];
            i++;
        }
        cout << i << " " << j << " " << cursum << endl;
        if(i==j-1 && (a[i]>=0))
        {
            cursum-=a[i];
            i++;
            continue;
        }
        minsum=min(minsum,cursum);
    }
    return minsum;
}
void solve()
{
    int n;cin >> n;
    
    vi a(n);cin >> a;
    if(n<=2)
    {
        cout << abs(accumulate(all(a),0LL)) << endl;
        return;
    }
    // int ans=accumulate(all(a),0LL);
    deb(f(a));
    // int ans_=f(a);
    // // deb(ans_);
    // if(ans_>0)
    // {
    //     cout << ans << endl;
    //     return;
    // }
    // // deb(ans);

    // cout << ans-2*ans_ << endl;
    // return;
    vi max_val(n+1),ans(n+1),sum(n+1),cur_sum(n+1);
    max_val[0] = -1e18-1;
    ans[0] = 0;
    sum[0] = 0;
    cur_sum[0] = 0;

    // int max_val = -1e18-1,ans=0;
    // int sum = 0,cur_sum = 0;
    for(int i=0;i<n;i++) 
    {
        // ans = min(ans, cur_sum+a[i] - max_val);
        // max_val = max(max_val, sum);
        // cur_sum += a[i];
        // sum += a[i];
        ans[i+1] = min(ans[i], sum[i] + a[i] - max_val[i]);
        max_val[i+1] = max(max_val[i], sum[i]);
        // cur_sum[i+1] = cur_sum[i] + a[i];
        sum[i+1] = sum[i] + a[i];
    }
    deb(ans);
    deb(max_val);
    deb(cur_sum);
    deb(sum);nl nl
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
    }
    int gen=0;
    int N=20;
    while(gen--)
    {
        int n=rand()%N+1;
        vi a(n);
        for(int i=0;i<n;i++) a[i]=rand()%1000-500;
        int ans=f(a);
        int ans_=0;
        vi max_val(n+1),sum(n+1),cur_sum(n+1);
        max_val[0] = -1e18-1;
        sum[0] = 0;
        cur_sum[0] = 0;
        for(int i=0;i<n;i++) 
        {
            ans_ = min(ans_, cur_sum[i] + a[i] - max_val[i]);
            max_val[i+1] = max(max_val[i], sum[i]);
            cur_sum[i+1] = cur_sum[i] + a[i];
            sum[i+1] = sum[i] + a[i];
        }
        if(ans!=ans_)
        {
            cout << "Failed" << endl;
            cout << n << endl;
            cout << a << endl;
            cout << ans << " " << ans_ << endl;
            break;
        }
    }

}