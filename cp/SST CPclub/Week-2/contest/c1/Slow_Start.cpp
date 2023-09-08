// https://www.codechef.com/problems/SLOWSTART
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--)
	{
	    int x,h;cin >> x >> h;
	    int y=x/2;
	    int ans = (h%y==0)?(h/y):(h/y+1);
	    if (ans <=5)
	    {
	        cout << ans << endl;
	        continue;
	    }
	    h-=5*y;
	    // cout << "h: " << h <<endl;
	    ans = 5 + ((h%x==0) ? (h/x) : (h/x+1));
	    cout << ans<<endl;
	}
	return 0;
}
 