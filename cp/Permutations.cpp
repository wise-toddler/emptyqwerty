#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string solve(int n)
{
    string s="";
    if(n==1)
        return "1";
    if(n==2 || n==3 )
        return "NO SOLUTION";
    bool flag=true;
    for(int i =2;i<=n;i+=2)
    {
        s+=to_string(i)+" ";
        if(i+2>n && flag)
        {
            i=-1;
            flag =false;
        }
    }
    return s;
}

int main() 
{
    int n ;
    cin >> n;
    cout << solve(n);
    
}

