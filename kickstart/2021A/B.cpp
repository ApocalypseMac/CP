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
int grid[1005][1005], dp[1005][1005][4];
// up left down right
int count(int a, int b){
    if (a == 1 or b == 1){
        return 0;
    }
    if (a < b){
        swap(a, b);
    }
    int res = 0;
    res += max(b / 2 - 1, 0);
    res += max(0, min(a / 2 - 1, b - 1));
    return res;
}

int main(){
    fast;
    int T;
    cin >> T;
    for (int ncase = 1; ncase <= T; ++ncase){
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                cin >> grid[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                if (grid[i][j]){
                    dp[i][j][0] = 1;
                    dp[i][j][1] = 1;
                    if (i > 0){
                        dp[i][j][0] += dp[i-1][j][0];
                    }
                    if (j > 0){
                        dp[i][j][1] += dp[i][j-1][1];
                    }   
                    
                }
            }
        }
        for (int i = r - 1; i >= 0; --i){
            for (int j = c - 1; j >= 0; --j){
                if (grid[i][j]){
                    dp[i][j][2] = 1;
                    dp[i][j][3] = 1;
                    if (i < r - 1){
                        dp[i][j][2] += dp[i+1][j][2];
                    }
                    if (j < c - 1){
                        dp[i][j][3] += dp[i][j+1][3];
                    }   
                    
                }
            }
        }
        // debug(cnt);
        // debug(dp[3][0][0]);
        // debug(dp[3][0][1]);
        // debug(dp[3][0][2]);
        // debug(dp[3][0][3]);
        // debug(dp[3][1][3]);
        // debug(dp[3][2][3]);
        // debug(grid[3][1]);
        ll res = 0;
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                if (grid[i][j]){
                    res += count((dp[i][j][0]), (dp[i][j][1]));
                    res += count((dp[i][j][2]), (dp[i][j][1]));
                    res += count((dp[i][j][0]), (dp[i][j][3]));
                    res += count((dp[i][j][2]), (dp[i][j][3]));
                }
                // debug(i);
                // debug(j);
                // debug(res);
            }
        }
        cout << "Case #" << ncase << ": " ;
        cout << res << endl;
    }
    return 0;
}