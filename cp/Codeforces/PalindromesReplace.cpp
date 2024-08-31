// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-2.md
// https://codeforces.com/group/MWSDmqGsZm/contest/223206/problem/A
#include <iostream>
using namespace std;
string solve(string s)
{
    string ret="";
    int n=s.size();
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='?')
            if(s[n-1-i]!='?')
                ret+=s[n-1-i];
            else
                ret+='a';
        else if(s[i]==s[n-1-i] || s[n-1-i]=='?')
                ret+=s[i];
        else 
            return "-1";
    }
    return ret;   
}


int main() 
{
    string s ;
    cin >> s;
    cout << solve(s);    
}