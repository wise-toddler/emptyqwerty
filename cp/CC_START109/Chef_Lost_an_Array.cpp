// https://www.codechef.com/START109C/problems/CLARR
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
bool isNonDecreasing(vi& a)
{
    for(int i=1;i<a.size();i++)
    {
        if(a[i]<a[i-1])return false;
    }
    return true;
}
bool isNonIncreasing(vi& a)
{
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>a[i-1])return false;
    }
    return true;
}
void solve()
{
    int n,d;cin>>n>>d;
    vi minarr(n),maxarr(n);
    cin>>maxarr;
    cin>>minarr;
    // check if non increasing
    if(! isNonIncreasing(minarr) || !isNonDecreasing(maxarr))
    {
        cout << "NO" << endl;
        return;
    }
    
    vi ans(n);
    if(minarr[0]!=maxarr[0])
    {
        cout << "NO" << endl;
        return;
    }
    ans[0]=maxarr[0];
    int i=1;
    int lcmin = 0,lcmax = 0;
    while(i<n)
    {
        if(ans[i-1]!=maxarr[i])
        {
            if(maxarr[i] - ans[lcmax] >d*(i-lcmax))
            {
                cout << "NO" << endl;
                return;
            }
            if(lcmax!=i-1)
            {
                while(lcmax!=i-1)
                {
                    ans[lcmax+1]=maxarr[lcmax+1];
                    lcmax++;
                }
            }
            ans[i]=maxarr[i];
            lcmax=i;
        }
        else if(ans[i-1]!=minarr[i])
        {
            if(ans[i-1]-d>minarr[i])
            {
                cout << "NO" << endl;
                return;
            }
            ans[i]=minarr[i];
        }
        else
        {
            ans[i]=INT32_MAX;
        }
        i++;
    }
    cout << "YES" << endl;
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
    }
}