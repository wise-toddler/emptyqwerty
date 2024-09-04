// https://codeforces.com/contest/1904/problem/C
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
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
//find closest element to x in a sorted array
int binarySearchClosest(vi& arr, int target) 
{
    int low = 0, high = arr.size() - 1;
    int closestElement = arr[0];

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target) 
            return arr[mid];  // Exact match found
        else if (arr[mid] < target) 
            low = mid + 1;
        else 
            high = mid - 1;

        // Update closestElement if the current element is closer to the target
        if (abs(arr[mid] - target) < abs(closestElement - target)) 
            closestElement = arr[mid];
    }
    return abs(closestElement - target);
}
void solve()
{
    int n,k;cin >> n >> k;
    vi a(n);cin >> a;
    sort(all(a));
    // find min diff;
    int ans=a[0];
    for(int i=1;i<n;i++)
    {
        ans=min(ans,a[i]-a[i-1]);
    }
    if(k==1)
    {
        cout << ans << endl;
        return;
    }
    if(k>2)
    {
        cout << 0 << endl;
        return;
    }
    int ans2=1e18;
    fo1(i,0,n-1,1)
        fo1(j,i+1,n,1)
            ans2=min(ans2,binarySearchClosest(a,(a[j]-a[i])));
    cout << min(ans,ans2) << endl;
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