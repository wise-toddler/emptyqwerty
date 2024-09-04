// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G
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
int gcd(int a, int b){return a%b==0?b:gcd(b,a%b);}
signed main()
{ 
    IOS
    int n;cin >> n;
    vi a(n);
    cin >> a[0];
    int g = a[0];
    for(int i=1;i<n;i++)
    {
        cin >> a[i];
        g = gcd(g,a[i]);
    }

    if(g!=1)
    {
        cout << -1 << endl;
        return 0;
    }

    int ans=n;
    int left=0;
    g=a[0];
    int rtol = 0;
    for(int i=0;i<n;i++)
    {
        g = gcd(g,a[i]);
        if(g==1)
        {
            g=a[i];       
            rtol = i;

            while (gcd(g, a[rtol])!= 1)
            {   
                g = gcd(g,a[rtol]);
                rtol--;
            }
            left = rtol;
            ans = min(ans,i-left+1);
            i=left+1; // sir bass itna hi change kara hogya 
            g=a[i];
        }
    }
    cout << ans << endl;
    // stack<int> s1,s2;
    // stack<int> g1,g2;
    // int ans = n;
    // // int gc = a[0];
    // for(int i=0;i<n;i++)
    // {
    //     if(!g2.empty() and g2.top()==1)
    //     {
    //         ans = min(ans,(int)s1.size()+1);
    //         g1.push(s2.top());
    //         while(!s2.empty())
    //         {
    //             if(!g1.empty())
    //                 g1.push(gcd(g1.top(),s2.top()));
    //             else
    //                 g1.push(s2.top());
    //             s2.pop();
    //             g2.pop();
    //             if(g1.top()==1)
    //                 ans = min(ans,(int)g1.size());                
    //         }

    //     }
    //     else
    //     {
    //         if(!g2.empty())
    //             g2.push(gcd(g2.top(),a[i]));
    //         else
    //             g2.push(a[i]);
    //         s2.push(a[i]);
    //     }
    // }
    // cout << ans << endl;
}
// 4 6 9 3 6
// s1:s2
/*
    :4              :4
    :4 6            :4 2
    :4 6 9          :4 2 1
        4 6 9:      1 3 9:

*/



// sir's appraoch
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

class Queue
{
    stack<pii> s1, s2;

    void moveElementsToFirstStack() {
        while(s2.size()) {
            int x = s2.top().first;
            int newGcd = (s1.size()) ? gcd(x, s1.top().second) : x;
            s1.push({x, newGcd});
            s2.pop();
        }
    }

public:

    void push(int x)  {
        int newGcd = (s2.size()) ? gcd(x, s2.top().second) : x;
        s2.push({x, newGcd});
    }

    void pop() {
        if(s1.size() == 0) {
            moveElementsToFirstStack();
        }
        s1.pop();
    }

    bool good() {
        int g = 0;
        if(s1.size()) g = gcd(g, s1.top().second);
        if(s2.size()) g = gcd(g, s2.top().second);
        return g == 1;
    }

    bool canRemoveFront() {
        if(s1.size() == 0) {
            moveElementsToFirstStack();
        }

        auto temp = s1.top();
        s1.pop();

        bool ans = good();

        s1.push(temp);

        return ans;
    }

    int size() {
        return s1.size() + s2.size();
    }
};


signed main() {
    IOS;

    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    int ans = INT_MAX;
    Queue q;
    for(int x : a) {
        q.push(x);
        while(q.size()) {
            if(q.canRemoveFront()) {
                q.pop();
            } else {
                break;
            }
        }
        if(q.good()) {
            ans = min(ans, q.size());
        }
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << endl;
}
*/