// https://codeforces.com/contest/1946/problem/B
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
int maxSubArray(vector<int> &nums)
{

    int n = nums.size();

    int cur_sum = 0;
    int max_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cur_sum < 0)
            cur_sum = 0;
        cur_sum += nums[i];
        max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
}
int pow(int a,int n)
{
    int m=1e9+7;
    if(n==0) return 1;
    if(n==1) return a;
    int ans=pow(a,n/2);
    ans=(ans*ans)%m;
    if(n%2) ans=(ans*a)%m;
    return ans%m;
}
int gp(int a,int r,int n)
{
    int m=1e9+7;
    // int ans= (a*(1-pow(r,n)))/(1-r);
    int ans= (a%m*(pow(r,n)-1)%m)%m;
    int den=pow(r-1,m-2);
    ans=(ans*den)%m;
    return ans;
}
void solve()
{
    int n,k;cin >> n >> k;
    int m=1e9+7;
    vi a(n);cin >> a;
    int ans=maxSubArray(a);
    
    int sum=0;
    for(int i:a)
        sum=(sum+i)%m;
    // deb(ans)deb(sum)
    int aa = gp(ans,2,k);
    // deb(aa)
    // int bb = gp(sum,k,n);
    cout << ((sum+aa)%m+m)%m << endl;
    

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    // cout << gp(12,2,3) << endl;
    while(t--)
    {
        solve();
    }
}