// https://codeforces.com/contest/1948/problem/B
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
int n;
// dp map id [2] = kya mei torda ke answer laa paaya yes no ya mei nhi torkke ans laa paya yes/no
vvi dp;
int rec(int id,vi& a)
{
    int is2 = to_string(a[id]).size()==2;
    auto [d1,d2] = make_pair(a[id]/10,a[id]%10);
    // 78 91 => 1
    // 7 8 91 => 1 
    if(id==-1) return 1;
    if(id==n-2) // last element reached
    {
        int breakans = is2 && (d1 <= d2) && d2<=a[id+1];
        int nobreakans = (a[id]<=a[id+1]);   
        dp[id][0] = breakans;
        dp[id][1] = nobreakans;
        return (nobreakans || breakans) && rec(id-1,a);
    }
    
    auto ba = dp[id+1][0];
    auto nba = dp[id+1][1];
    if(nba==1)
    {
        if(a[id]<=a[id+1])
        {
            dp[id][1] = 1;
            return 1 && rec(id-1,a);
        }
        else if(is2 && d1<=d2 && d2<=a[id+1])
        {
            dp[id][0] = 1;
            return 1 && rec(id-1,a);
        }
    }
    if(ba==1)
    {
        int d3 = a[id+1]/10;
        if(a[id]<=d3)
        {
            dp[id][1] = 1;
            return 1 && rec(id-1,a);
        }
        else if(is2 && d1<=d2 && d2<=d3)
        {
            dp[id][0] = 1;
            return 1 && rec(id-1,a);
        }
    }
    return 0;

}
void solve()
{
    cin >> n;
    vi a(n);cin >> a;
    // dp.clear();
    dp.assign(n,vi(2,-1));
    // check if adjacent elements are non decreasing if yes go on if no then check if the can be broken into 2 digits 
    // if yes then go on if no then print -1
    int ans = rec(n-2,a);
    cout << (ans?"YES":"NO") << endl;
    // for(auto& x : dp)
    // {
    //     cout << x << endl;
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
    // fon(i,100)
    // {
    //     int sz = rand()%10;
    //     cout << sz << endl;
    //     fon(j,sz)
    //         cout << rand()%100 << " ";
    //     nl
    // }
}

/*
YES
3
86 77 15
3
35 86 92
9
21 62 27 90 59 63 26 40 26
2
36 11
8
67 29 82 30 62 23 67 35
9
2 22 58 69 67 93 56 11 42
9
73 21 19 84 37 98 24 15 70
3
26 91 80
6
73 62 70 96 81 5
5
84 27 36 5 46
9
13 57 24 95 82 45 14 67 34
4
43 50 87 8
6
78 88 84 3 51 54
9
32 60 76 68 39 12 26 86 94
9
95 70 34 78 67 1 97 2 17
2
52 56
1
80
6
41 65 89 44 19 40
9
31 17 97 71 81 75 9 27 67
6
97 53 86 65 6 83
9
24 28 71 32 29 3 19 70 68
8
15 40 49 96 23 18 45 46
1
21
5
79 88 64 28 41
0

3
0 34 64
4
14 87 56 43
1
27
5
59 36 32 51 37
8
75 7 74 21 58 95 29 37
5
93 18 28 43 11
8
29 76 4 43 63 13 38 6
0

4
18 28 88 69
7
17 96 24 43 70 83 90
9
72 25 44 90 5 39 54 86 69
2
42 64
7
7 55 4 48 11 22 28
9
43 46 68 40 22 11 10 5 1
1
30
8
5 20 36 44 26 22 65 8
6
82 58 24 37 62 24
0

6
52 99 79 50 68 71
3
31 81 30
3
94 60 63
9
81 99 96 59 73 13 68 90 95
6
66 84 40 90 84 76
2
36 7
5
56 79 18 87 12
8
72 59 9 36 10 42 87 6
1
13
2
21 55
9
99 21 4 39 11 40 67 5 28
7
50 84 58 20 24 22 69
6
81 30 84 92 72 72
0

5
85 22 99 40 42
8
13 98 90 24 90 9 81 19
6
32 55 94 4 79 69
3
76 50 55
0

2
79 84
3
5 21 67
4
13 61 54 26
9
44 2 2 6 84 21 42 68 28
9
72 8 58 98 36 8 53 48 3
3
33 48 90
4
67 46 68 29
0

6
88 97 49 90 3 33
3
97 53 92
6
25 52 96 75 88 57
9
36 60 14 21 60 4 28 27 50
8
56 2 94 97 99 43 39 2
8
3 0 81 47 38 59 51 35
4
39 92 15 27
4
29 49 64 85
9
43 35 77 0 38 71 49 89 67
8
92 95 43 44 29 90 82 40
1
69
6
32 61 42 60 17 23
1
81
9
90 25 96 67 77 34 90 26 24
7
14 68 5 58 12 86 0
6
26 94 16 52 78 29
6
90 47 70 51 80 31
3
57 27 12
6
14 55 12 90 12 79
0

9
89 74 55 41 20 33 87 88 38
6
70 84 56 17 6 60
9
37 5 59 17 18 45 83 73 58
3
37 89 83
7
78 57 14 71 29 0 59
8
38 25 88 74 33 57 81 93
8
70 99 17 39 69 63 22 94
3
47 31 62
2
90 92
1
57
*/