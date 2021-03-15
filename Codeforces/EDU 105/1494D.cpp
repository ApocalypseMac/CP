#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
const int MOD = 1e9 + 7;
// dsu
int p[555];
int find(int i){
    if (p[i] != i)
        p[i] = find(p[i]);
    return p[i];
}
bool unionSet(int i, int j){
    int pi = find(i), pj = find(j);
    if (pi != pj){
        if (pi < pj){
            swap(pi, pj);
        }
        p[pj] = pi;
        return true;
    }
    else
        return false;
}


int main(){
    fast;
    int n;
    cin >> n;
    int m = 2 * n - 1;
    int edge[n][n];
    vector<int> sa(m, 0);
    vector<int> fa(m, -1); // 0 - m-1
    multimap<int, int> mp;
    for (int i = 0; i < n; ++i){
        p[i] = i;
        for (int j = 0; j < n; ++j){
            cin >> edge[i][j];
            if (i == j){
                sa[i] = edge[i][i];
            }
            else if (i < j){
                mp.insert({edge[i][j], i * 500 + j});
            }
        }
    }
    
    int curr = n - 1;
    for (auto [k, val]: mp){
        // cout << k << ' ' << val << endl;
        int u = val % 500, v = val / 500;
        int fu = u, fv = v;
        if(unionSet(u, v)){
            // debug(1);
            while (fa[fu] != -1){
                fu = fa[fu];
            }
            while (fa[fv] != -1){
                fv = fa[fv];
            }
            // debug(fu);
            // debug(fv);
            if (fu != fv){
                if (sa[fu] < k and sa[fv] < k){
                    ++curr;
                    sa[curr] = k;
                    fa[fu] = curr;
                    fa[fv] = curr;
                }
                else if (sa[fu] < k){
                    fa[fu] = fv;
                }
                else {
                    fa[fv] = fu;
                }
                
            }
            // for(int i = 0; i < m; ++i){
            //     cout << ' ' << fa[i];
            // }
            // cout << endl;
        }
    }


    // output
    cout << curr + 1 << endl;
    for(int i = 0; i <= curr; ++i){
        cout << sa[i] << ' ';
    }
    cout << endl;
    cout << curr + 1 << endl;
    for(int i = 0; i < curr; ++i){
        if (fa[i] != -1){
            cout << i + 1 << ' ' << fa[i] + 1 << endl; // 1 - m
        }
    }
    return 0;
}