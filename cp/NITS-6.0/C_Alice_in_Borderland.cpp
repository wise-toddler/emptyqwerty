// https://codeforces.com/gym/502762/problem/C
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
void solve()
{
    int n,s;cin >> n >> s;
    vi a(n);cin >> a;
    sort(all(a));
    vi score(n); // number of elements smaller than a[i]
    int c=0;
    int sm=1;
    // cout << score << endl;


    int i=0,j=0;
    int l=0;
    int sum=0;
    int st=0;
    while(j<n)
    {
        if(sum+a[j]<=s)
        {
            sum+=a[j];
            j++;
        }
        else
        {
            sum-=a[i];
            i++;
        }
        if((j-i)>=l)
        {
            l=j-i;
            st=i;
        }
    }
    int r = l+st-1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            score[i]=0;
        else
        {
            if(a[i]==a[i-1])
            {
                score[i]=c;
                sm++;
            }
            else
            {
                c+=sm;
                sm=1;
                score[i]=c;
            }
        }
    }
    for(int i=0;i<n;i++)
        if(i<st || r<i)
            score[i]++;
    sort(all(score));
    // cout << l << " " << st << endl;
    // cout << score << endl;

    // int rank= (n-(st+l)+1);
    // if(rank!=1)
    // {
        
    //     int hr = n-rank+1;
    //     // deb(hr)
    //     int hscore = lower_bound(all(a),a[hr])-a.begin();
    //     if(l==(hscore+1))
    //         rank--;
    //     // deb(hscore)
    // }
    // cout << lower_bound(all(score),l)-score.begin() << endl;
    int rank=end(score)-upper_bound(all(score),l);
    // cout << (n-(st+l)+1) << endl;
    cout << rank+1 << endl;
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