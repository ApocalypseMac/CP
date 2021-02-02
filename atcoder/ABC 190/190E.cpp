#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main(){
    fast;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    int u, v;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        edges[v].emplace_back(u);
        edges[u].emplace_back(v);
    }
    int k;
    cin >> k;
    vector<int> c(k);
    int dis[k][k];
    for (int i = 0; i < k; ++i){
        cin >> c[i];
        for (int j = 0; j < k; ++j){
            dis[i][j] = -1;
        }
    }
    for (int i = 0; i < k; ++i){
        deque<int> q = {c[i]};
        vector<int> dd(n + 1, -1);
        dd[c[i]] = 0;
        int curr, d = 0, sz;
        while (!q.empty()){
            ++d;
            sz = q.size();
            for (int i = 0; i < sz; ++i){
                curr = q.front();
                q.pop_front();
                for (auto next: edges[curr]){
                    if (dd[next] == -1){
                        q.emplace_back(next);
                        dd[next] = d;
                    }
                }
            }
        }
        for (int j = 0; j < k; ++j){
            dis[i][j] = dd[c[j]];
        }
    }
    // for (int i = 0; i < k ; ++i){
    //     for (int j = 0; j < k; ++j){
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int dp[1<<k][k];
    for (int i = 0; i < 1 << k; ++i){
        for (int j = 0; j < k; ++j){
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < k; ++i){
        dp[1<<i][i] = 1;
    }
    for (int mask = 1; mask < 1 << k; ++mask){
        for (int i = 0; i < k; ++i){
            if (mask >> i & 1){
                for (int j = 0; j < k; ++j){
                    if ((mask >> j & 1) == 0 and dis[i][j] > 0){
                        dp[mask|(1<<j)][j] = min(dp[mask|(1<<j)][j], dp[mask][i] + dis[i][j]);
                    }
                }
            }
        }
    }
    // for (int i = 0; i < 1 << k; ++i){
    //     for (int j = 0; j < k; ++j){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int res = INF;
    for (int i = 0; i < k; ++i){
        res = min(res, dp[(1<<k)-1][i]);
    }
    if (res == INF){
        cout << -1 << endl;
    }
    else{
        cout << res << endl;
    }

    return 0;
}