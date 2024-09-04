// https://www.codechef.com/START107C/problems/ODDMATRIX
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
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        //cout << i << ' ';
        print(v[i]);
    }
}

vii make1s0s(int n)
{
    vii v(n,vi(n,0));
    if(n%4==0)
    {
        fo1(i,0,n/2+1,1)
            fo1(j,0,n/2+1,1)
                v[i][j]=1;
        fo1(i,n/2+1,n,1)
            fo1(j,n/2+1,n,1)
                v[i][j]=1;
    }
    else
    {
        fo1(i,0,n/2,1)
            fo1(j,0,n/2,1)
                v[i][j]=1;
        fo1(i,n/2,n,1)
            fo1(j,n/2,n,1)
                v[i][j]=1;
    }
    return v;
} 
// check if all rows sum and col sum are odd 
bool check(vii v)
{
    int n = v.size();
    vi row(n,0);
    vi col(n,0);
    fo1(i,0,n,1)
    {
        fo1(j,0,n,1)
        {
            row[i]+=v[i][j];
            col[j]+=v[i][j];
        }
    }
    fo1(i,0,n,1)
    {
        if(row[i]%2==0 || col[i]%2==0) return 0;
    }
    return 1;
}
vii generateMagicSquare(int N)
{
    vii magicSquare(N, vector<int>(N, 0));

    int n = 1;
    int i = 0, j = N / 2;

    while (n <= N * N)
    {
        magicSquare[i][j] = n;
        n++;
        int newi = (i - 1 + N) % N;
        int newj = (j + 1) % N;
        if (magicSquare[newi][newj] != 0)
        {
            i = (i + 1) % N;
        }
        else
        {
            i = newi;
            j = newj;
        }
    }
    return magicSquare;
}
void solve()
{
    int N;cin>>N;
    if(N%2==1)
    {
        vii magicSquare = generateMagicSquare(N);
        assert(check(magicSquare));
        print(magicSquare);
    }
    else
    {
        vii a = make1s0s(N);
        int e = 1,o = 2;
        fo1(i,0,N,1)
        {
            fo1(j,0,N,1)
            {
                if(a[i][j]==1) a[i][j] = e,e+=2;
                else a[i][j] = o,o+=2;
            }
            // cout << endl;
        }
        assert(check(a));
        print(a);
    }
    cout << endl;

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
    // fo1(i,1,301,1)
    // {
    //     cout << i << " ";
    //     // solve();
    // }
}
/*
int arr[]={12,123,1234,12345,123456,1234567,12345678,123456789,23,234,2345,23456,234567,2345678,23456789,34,345,3456,34567,345678,3456789,45,456,4567,45678,456789,56,567,5678,56789,67,678,6789,78,789,89};
    
1100
1100
0011
0011

111000
111000
111000
000111
000111
000111

11111000 
11111000
11111000
11111000
11111000
00000111
00000111
00000111

34
30
*/