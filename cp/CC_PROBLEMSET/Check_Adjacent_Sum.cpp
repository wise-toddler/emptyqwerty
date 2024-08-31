// https://www.codechef.com/START123B/problems/CHECKADJSUM
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
vector<int> twoSum(vector<int> &nums, int target)
{
    int n=nums.size();
    int i =0;   
    int j = n-1;
    while(i<j)
    {
        if(nums[i]+nums[j]==target)
            return {i,j};
        else if(nums[i]+nums[j]<target)
            i++;
        else
            j--;
    }
    return {-1,-1};
}
void solve()
{
    int n,q;cin >> n >> q;
    vi c(n);cin >> c;
    sort(all(c));
    int atmost = accumulate(all(c),0LL);
    while(q--)
    {

        int x;cin >> x;
        x= 2*atmost-x;
        // two sum;
        // deb(x)
        // deb(a)
        vi a = c;
        vi ans = twoSum(a,x);
        sort(all(ans));
        vi ans2 = {a[ans[0]],a[ans[1]]};
        // cout << ans << endl;
        if(ans[0]==-1)
        {
            cout << "-1" << endl;
            continue;
        }
        // remove ans[0] and ans[1] from a and add at first and last
        cout << ans2[0] << " ";
        // a.erase(find(all(a),ans[0]));
        a.erase(a.begin()+ans[0]);
        a.erase(a.begin()+ans[1]-1);
        for(auto i:a)
            cout << i << " ";
        cout << ans2[1] << endl;
    }

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