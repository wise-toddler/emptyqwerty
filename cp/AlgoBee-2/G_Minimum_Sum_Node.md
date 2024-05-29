## Problem: [G. Minimum Sum Node](https://codeforces.com/gym/517983/problem/G)
<details>
<summary>Hint 1</summary>

```
Think of a in-out tree dp.
```
</details>

<details>
<summary>Hint 2</summary>

```
in[u]: This represents the total of distances from node u to all other nodes within the subtree that has u as its root.
out[u]: This signifies the total of distances from node u to all other nodes that are not part of the subtree with u as its root.
With these values, we can compute the result for every node.
ans[u] = in[u] + out[u]: This equation gives us the total distance from node u to all other nodes in the tree.
Finally, we can go through all the computed results and identify the smallest one.
```

</details>

<details>
<summary>Solution</summary>

```
Calculating in[u] is quite straightforward. Suppose we want to calculate the sum of distances starting at node u and ending at any node in subtree rooted at v. We can use the pre-calculated value for v and separately add the contribution created by edge u→v. This extra quantity will be the subtree size of u. Then we can repeat the process for each child of u.
```

<font size="4">

$in[u] = \sum_{v \in \text{{children of }} u} (in[v] + sub[v])$

</font>

```
To calculate out[u], first let's calculate the contribution of parent of u. We can use out[par] and add the difference created by the edge u→par which is n-sub[par]+1. Next, we add the contribution of each sibling of u: in[sib] + sub[sib]*2.
Finally we have the following formula:
```
<font size="4">

$out[u] = out[\text{{par}}] + (n - sub[\text{{par}}] + 1) + (\sum_{\text{{sib}}} (in[\text{{sib}}] + 2 \cdot sub[\text{{sib}}])) - (in[u] + 2 \cdot sub[u])$
</font>

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

int contribution(pii x) {
    return x.first + x.second;
}

void solve() {
    int n;
    cin >> n;
    vvi adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pii> dp(n+1);
    function<void(int,int)> dfs1 = [&](int nd, int pr) {
        for(int i : adj[nd]) {
            if(i == pr) continue;
            dfs1(i, nd);
            dp[nd].first += contribution(dp[i]);
            dp[nd].second += dp[i].second;
        }
        dp[nd].second++;
    };
    dfs1(1, 0);

    vi up(n+1);
    function<void(int,int)> dfs2 = [&](int nd, int pr) {
        if(pr) {
            up[nd] = dp[pr].first - contribution(dp[nd]) + (dp[pr].second - dp[nd].second);
            up[nd] += up[pr] + n - dp[pr].second;
        }
        for (int i : adj[nd]) {
            if (i == pr) continue;
            dfs2(i, nd);
        }
    };
    dfs2(1, 0);

    vi ans(n);
    for(int i = 1; i <= n; i++) {
        ans[i-1] = dp[i].first + up[i];
    }
    int minn = *min_element(ans.begin(), ans.end());
    int cntmin = count(ans.begin(), ans.end(), minn);
    cout << cntmin << endl;
    for(int i = 0; i < n; i++) {
        if(ans[i] == minn) {
            cout << i+1 << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
```