// https://codeforces.com/problemset/problem/1593/B
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-2.md
#include <iostream>
#include <algorithm>
using namespace std;
int zero5or0(string s)
{
    int n = s.size();
    int index=-1;
    for ( int i = n-1 ; i >=0 ; i-- ) 
    {
        if (s[i]=='0')
        {
            index=i;
            break;
        }
    }
    for ( int i = index-1 ; i >=0 ; i-- ) 
    {
        if (s[i]=='0' || s[i]=='5')
        {
            return n-2-i; 
        }
    }
    return 20;
}

int five2or7(string s)
{
    int n = s.size();
    int index=-1;
    for ( int i = n-1 ; i >=0 ; i-- ) 
    {
        if (s[i]=='5')
        {
            index=i;
            break;
        }
    }
    for ( int i = index-1 ; i >=0 ; i-- ) 
    {
        if (s[i]=='2' || s[i]=='7')
        {
            return n-2-i; 
        }
    }
    return 20;
}

int solve(string s)
{
    return min(zero5or0(s),five2or7(s));
}


int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;    
    }
}