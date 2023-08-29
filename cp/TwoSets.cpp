#include <iostream>
using namespace std;
void solve(long n)
{
    if(n%4==0 or n%4==3)
    {
        cout << "YES" <<endl;
        if(n%2==1)
        {
            int t =n/4;
            int x=1;
            cout << n/2 << endl;
            while(x<=t)
                cout << x <<" "<< n+1-x++<<" ";

            cout << n+1-x << endl << n-n/2 <<endl;

            for (int i = x; i < n+1-x; i++)
                cout << i << " ";            
        }
        else
        {
            cout << n/2 << endl;
            int i =1;
            while(i<=n/4)
                cout << i << " " << n+1-i++<<" ";
            cout << endl << n/2 << endl;
            while(i<=n/2)
                cout << i << " " << n+1-i++<<" ";
        }
    }
    else cout << "NO";
}
int main() 
{
    int n ;
    cin >> n;
    solve(n);    
}

