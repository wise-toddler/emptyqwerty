// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true
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
// a recursive function to divide the array into two parts till there r 2 elements in the array and then multiply them

string add(string a,string b)
{
    int n = a.size();
    int m = b.size();
    if(n<m) return add(b,a);
    int carry = 0;
    string ans = "";
    for(int i=n-1;i>=0;i--)
    {
        int temp = a[i]-'0'+carry;
        if(i-n+m>=0)
            temp += b[i-n+m]-'0';
        carry = temp/10;
        ans += to_string(temp%10);
    }
    if(carry)
        ans += to_string(carry);
    reverse(all(ans));
    return ans;
}
string mul(string a,string b)
{
    int n = a.size();
    int m = b.size();
    if(n<m) return mul(b,a);
    for(int i=0;i<n-m;i++)
        b += "0";
    reverse(all(a));
    reverse(all(b));
    string carry = "";
    string ans = "";    
    int ord = 0;
    while(ord<n)
    {
        string temp = carry;
        for(int i=0;i<=ord;i++)
            temp = add(temp,to_string((a[i]-'0')*(b[ord-i]-'0')));
        
        ans = temp.back()+ans;
        temp.pop_back();
        carry = temp;
        ord++;
    }
    reverse(all(a));
    reverse(all(b));
    ord = n-2;
    while(ord>=0)
    {
        string temp = carry;
        for(int i=0;i<=ord;i++)
            temp = add(temp,to_string((a[i]-'0')*(b[ord-i]-'0')));
        
        ans = temp.back()+ans;
        temp.pop_back();
        carry = temp;
        ord--;
    }
    ans = carry+ans;
    return ans.substr(0,ans.size()-(n-m));
}
string mmq(vector<string> a)
{
    if(a.size()==1) return a[0];
    if(a.size()==2) return mul(a[0],a[1]);
    vector<string> b(a.size()/2);
    vector<string> c(a.size()-a.size()/2);
    for(int i=0;i<a.size();i++)
    {
        if(i<a.size()/2)
            b[i]=a[i];
        else
            c[i-a.size()/2]=a[i];
    }
    return mul(mmq(b),mmq(c));
}
void extraLongFactorials(int n) 
{
    // vector<string> a(n);
    // for(int i=1;i<=n;i++)
    //     a[i-1]=to_string(i);   
    string ans = "1";
    for(int i=1;i<=n;i++)
        ans = mul(ans,to_string(i));
    cout << ans << endl;
}
void solve()
{
    int n; cin >> n;
    extraLongFactorials(n);
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}