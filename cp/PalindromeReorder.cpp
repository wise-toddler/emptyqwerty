#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string Solve(vector<int>& a,int n)
{
    string s="";
    int count=0,index=-1;
    for (int i = 0; i < 26; i++)
    {
        if(a[i]%2!=0)
        {
            count++;
            index=i;
        }    
        
        if(count==2)
            break;
    }

    if(count<=1)
    {
        for (int i = 0; i < 26; i++)
        {
            int x=a[i]/2;
            for (int j = 0; j < x; j++)
            {
                s+=(char)(i+65);
            }   
        }
        int size=s.size();
        if(count==1)
            s+=(char)(index+65);
        for (int i = size-1; i >=0; i--)
        {
            s+=s[i];
        }
        return s;
    }
    else 
        return "NO SOLUTION";
}

int main() 
{
    string s = "";
    cin >> s;
    int n = s.size();
    vector<int> a(26,0);
    for(int i =0;i<n;i++)
        a[(int)s[i]-65]++;
    cout << Solve(a,n) << endl;
}
