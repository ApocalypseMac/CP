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
const int INF = 0x3f3f3f3f;
int h[555][555], v[555][555], res[555][555];
int dp[555][555][10];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(){
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m - 1; ++j){
            cin >> h[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < m; ++j){
            cin >> v[i][j];
        }
    }
    if (k % 2 == 1){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    
    int cost, ni, nj, ii, jj;
    for (int step = 1; step <= k / 2; ++ step){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cost = INF;
                for (int d = 0; d < 4; ++d){
                    ni = i + dir[d][0];
                    nj = j + dir[d][1];
                    if (ni >= 0 and ni < n and nj >= 0 and nj < m){
                        if (d % 2 == 0){ // v
                            ii = min(i, ni);
                            jj = nj;
                            cost = min(cost, 2 * v[ii][jj] + dp[ni][nj][step-1]);
                        }
                        else{ // h
                            ii = ni;
                            jj = min(j, nj);
                            cost = min(cost, 2 * h[ii][jj] + dp[ni][nj][step-1]);
                        }
                        // cout << ' ' << i << ' ' << j << ' ' << ni << ' ' << nj << ' ' << cost << endl;
                    }
                }
                dp[i][j][step] = cost;
                
            }
        }
        // debug(step);
        // for (int i = 0; i < n; ++i){
        //     for (int j = 0; j < m; ++j){
        //         cout << dp[i][j][step] << ' ';
        //     }
        //     cout << '\n';
        
        // }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cout << dp[i][j][k/2] << ' ';
        }
        cout << '\n';
    }
    return 0;
}