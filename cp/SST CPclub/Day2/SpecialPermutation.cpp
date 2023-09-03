#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int a;cin >> a;
        int b;cin >> b;
        if((b>=n/2+1 && a<=n/2) || (a==n/2+1 && b==n/2))
        {
            cout << a;
            for(int i =n/2+1;i<=n;i++) 
                if(i!=a && i!=b) 
                    cout << " " << i;
            
            cout << " " <<b;
            
            for(int i =1;i<=n/2;i++) 
                if(i!=a && i!=b) 
                    cout << " " << i;
        }
        else 
            cout << -1;
        cout << endl;

    }
}