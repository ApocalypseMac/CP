#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define flush cout.flush()
typedef long long ll;
const int MOD = 1e9 + 7;
// bool edges[22][22];
bool vis[22];
int color[22];
vector<vector<int>> nbs(22, vector<int>());
vector<int> dfsseq;
int sz;

// dsu
// int p[22];
// int find(int i){
//     if (p[i] != i)
//         p[i] = find(p[i]);
//     return p[i];
// }
// bool unionSet(int i, int j){
//     int pi = find(i), pj = find(j);
//     if (pi != pj){
//         if (pi > pj){
//             swap(pi, pj);
//         }
//         p[pi] = pj;
//         return true;
//     }
//     else
//         return false;
// }

void dfs(int u){
    vis[u] = true;
    dfsseq.emplace_back(u);
    for (auto v: nbs[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
}

ll dfs1(int idx){
    ll res = 0;
    if (idx == sz - 1){
        return 1;
    }
    int u = dfsseq[++idx];
    for (int c = 1; c <= 3; ++c){
        bool flag = true;
        for (auto v: nbs[u]){
            if (color[v] == c){
                flag = false;
                break;
            }
        }
        if (flag){
            color[u] = c;
            res += dfs1(idx);
            color[u] = 0;
        }
    }
    return res;
}

int main(){
    fast;
    int n, m;
    cin >> n >> m;
    ll res = 1;
    // for (int i = 0; i < n; ++i){
    //     p[i] = i;
    // }
    int u, v;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        --u;
        --v;
        // unionSet(u, v);
        nbs[u].emplace_back(v);
        nbs[v].emplace_back(u);
    }
    // for (int i = 0; i < n; ++i){
    //     for (auto uu: nbs[i]){
    //         cout << "   " << uu;
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; ++i){
        if (!vis[i]){
            dfsseq.clear();
            dfs(i);
            sz = dfsseq.size();
            // for (auto u: dfsseq){
            //     cout << ' ' << u;
            // }
            // cout << endl;
            // debug(sz);
            
            if (sz == 1){
                res *= 3;
            }
            else{
                color[dfsseq[0]] = 1;
                res *= 3 * dfs1(0);
            }
        }
        
    }
    cout << res << endl;
    return 0;
}