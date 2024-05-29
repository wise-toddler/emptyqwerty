# Problem: [C. Thala for a Reason](https://codeforces.com/gym/517983/problem/C)
<details>
<summary>Hint 1</summary>

```
Simple recurrsion with memoization can solve the problem.
```
</details>

<details>
<summary>Hint 2</summary>

```
We can go through all the possible moves and recursively call the function with the updated values.
so there are 7 possible moves:
```

1. dot ball -> f(x, y, balls-1)
2. 1 run -> f(x-1, y, balls-1)
3. 2 runs -> f(x-2, y, balls-1)
4. 3 runs -> f(x-3, y, balls-1)
5. 4 runs -> f(x-4, y, balls-1)
6. 6 runs -> f(x-6, y, balls-1)
7. wicket -> f(x, y-1, balls-1)

</details>

<details>
<summary>Solution</summary>

```
So the recursive function will be like this:

f(x, y, balls) = f(x, y, balls-1) + f(x-1, y, balls-1) + f(x-2, y, balls-1) + f(x-3, y, balls-1) + f(x-4, y, balls-1) + f(x-6, y, balls-1) + f(x, y-1, balls-1)
 
```

</details>

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int x, y;
int dp[101][11][7];
int dx[] = {0,1,2,3,4,6,0};
int dy[] = {0,0,0,0,0,0,-1};

int f(int x, int y, int balls) {
    if(x <= 0) return 1;
    if(balls == 0 || y == 0) return 0;
    if(dp[x][y][balls] != -1) return dp[x][y][balls];
    int ans = 0;
    for(int i = 0; i < 7; ++i) {
        ans += f(x-dx[i], y+dy[i], balls-1);
    }
    return dp[x][y][balls] = ans;
}

void solve() {
    cin >> x >> y;
    memset(dp, -1, sizeof dp);
    cout << f(x, y, 6) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
```