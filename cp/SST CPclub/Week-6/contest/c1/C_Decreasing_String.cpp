// https://codeforces.com/contest/1886/problem/C
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
int n,pos;
int f(int x){ return x*(x+1)/2;}

int g(int x){ return f(n)-f(n-x);}
bool check(int mid)
{
    return g(mid) < pos;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        n = s.size();
        
        cin >> pos;
        // map<char,vi> mp;
        // for(int i=0;i<n;i++) mp[s[i]].pb(i);
        int st=1,en=n;
        int si = 0;
        while(st<=en)
        {
            int mid = st+(en-st)/2;
            if(check(mid)) 
            {
                si = mid;
                st = mid+1;
            }
            else 
                en = mid-1;
        }
        pos -= g(si);
        pos--;
        string ans = "";
        // debug(ans)
        // cout << si << ' ' << pos << endl;
        int toremove = si;
        // debug(toremove)
        // set<int> rem;
        // for(int i=0;i<n;i++) rem.insert(i);
        // set<int> rem2;
        // cout <<"^ " <<ans.size() << endl;
        
        for(int i =0;i<n;i++)
        {
            while(ans.size()!=0 and (ans[ans.size()-1]>s[i]) and toremove!=0)
            {
                // debug(ans)
                ans.pop_back();
                toremove--;
                // cout << "removing " << s[i] << endl;
            }
            ans+=s[i];
        }
            // debug(ans)

        
        // for(int i =1;i<n && toremove!=0;i++)
        // {
        //     if(i<=0) i=1;
        //     if(ans[i] < ans[i-1]) 
        //     {
        //         ans.erase(ans.begin()+i-1); 
        //         i-=2;
        //         toremove--;
        //     }
        // }
        while(toremove!=0)
        {
            ans.pop_back();
            toremove--;
        }
        // debug(ans)
        cout << ans[pos];
    }
}

/*


pbdtm

pbdtm
bdtm


pbdtm

pbdtm

ans = ""
p

5 4 3 2 1
5 9 12 14 15


zcbm
abcdgh
abcdg
for (char c : s) {
        while (num && !ans.empty() && c < ans.back()) {
            ans.pop_back();
            num--;
        }
        ans += c;
    }


wygnotgsno

adgc -> adc -> ac

ids: {0,   3}
canBeRemoved: { }


*/
