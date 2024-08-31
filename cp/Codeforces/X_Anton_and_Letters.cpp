// https://codeforces.com/group/isP4JMZTix/contest/392597/problem/X
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
signed main()
{
    string s;
    getline(cin,s);
    unordered_set<char> st;
    for(char i : s)
    {
        if('a'<=i && i<='z')
        {
            st.insert(i);
        }
    }
    cout<<st.size()<<endl;
} 