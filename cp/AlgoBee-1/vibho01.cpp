// 
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
// int to_base_5(int n)
// {
//     int ans=0;
//     int p=1;
//     while(n)
//     {
//         ans+=(n%5)*p;
//         p*=10;
//         n/=5;
//     }
//     return ans;
// }
map<char,char> mp;
int e=0;
void g(string &s)
{
    // cout << e++ << " " << s << endl;
    if(s.size()==0) return;
    char c=s.back();
    if(c=='0') 
    {
        if(s.size()==1) {
            s="";
            return;
        }
        // bring a 1 from the left
        for(int i=s.size()-2;i>=0;i--)
        {
            if(s[i]!='0')
            {
                s[i]--;
                for(int j=i+1;j<s.size();j++)
                {
                    s[j]='4';
                }
                break;
            }
        }
    }
    c=mp[c];
    string t = s.substr(0, s.size() - 1);
    g(t);
    s=t+c;   
    return;
}
void solve()
{
    int n;cin >> n;
    //  change n to base 5 

    string st;    
    while(n)
    {
        st+=to_string(n%5);
        n/=5;
    }
    reverse(all(st));  
    mp['0']='9';
    mp['1']='1';
    mp['2']='3';
    mp['3']='5';
    mp['4']='7';
    // cout << st << endl;
    g(st);
    cout << st << endl;

    // vi a;
    // for(int i=1;i<=100;i++)
    // {
    //     string s=to_string(i);
    //     if(s[0]=='2' || s[0]=='4' || s[0]=='6' || s[0]=='8') 
    //     {
    //         i+=pow(5,s.size()-1)-1;
    //         continue;
    //     }
    //     if(s.find('0')==string::npos && s.find('2')==string::npos && s.find('4')==string::npos && s.find('6')==string::npos && s.find('8')==string::npos)
    //     {
    //         a.pb(i);
    //     }
    // }
    // for(int i=0;i<a.size();i++)
    // {
    //     cout << i+1 << " " << a[i] << " " <<to_base_5(i+1) << endl;
    // }
    // // last 5 itrs
    // fo1(i,a.size()-5,a.size(),1)
    // {
    //     cout <<i+1 <<" "<< a[i] << endl;
    // }
    
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