// https://www.facebook.com/codi ngcompetitions/hacker-cup/2023/practice-round/problems/C?source=facebook
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

bool allSame(vector<int> &a, int sum, int start, int end) {
    while (start < end)
    {
        if(a[start] + a[end] != sum) return false;
        ++start;
        --end;
    }
    return true;
}

int check(vector<int> &a, int sum) {
    int start = 0;
    int end = a.size() - 1;

    while(start < end) {
       if(a[start] + a[end] == sum) {
            ++start;
            --end;
       } else if(a[start] + a[end] < sum) {
            int ans = sum - a[start];
            if(allSame(a, sum, start + 1, end)) {
                return ans;
            }
            return INT64_MAX;
       } else {
            int ans = sum - a[end];
            if(allSame(a, sum, start, end - 1)) {
                return ans;
            }
            return INT64_MAX;
       }
    }

    return sum - a[start];
}

void solve() {
    int n; cin >> n;
    n = 2 * n - 1;
    vector<int> a(n);

    for(int &x : a) 
        cin >> x;

    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    
    sort(all(a));

    // inserting x at last
    int sum1 = a[1] + a[n - 1];
    int ans1 = allSame(a, sum1, 1, n - 1) ? sum1 - a[0] : INT64_MAX;
    
    if(ans1 <= 0) ans1 = INT64_MAX;

    // inserting x at beginning
    int sum2 = a[0] + a[n - 2];
    int ans2 = allSame(a, sum2, 0, n - 2) ? sum2 - a[n - 1] : INT64_MAX;

    if(ans2 <= 0) ans2 = INT64_MAX;


    // insert x in the middle
    int sum3 = a[0] + a[n - 1];
    int ans3 = check(a, sum3);

    if(ans3 <= 0) ans3 = INT64_MAX;
    
    int ans = min({ans1, ans2, ans3});
    cout << (ans == INT64_MAX ? -1 : ans) << endl;
}



signed main()
{
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

/*


*/