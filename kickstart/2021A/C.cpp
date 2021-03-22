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
int grid[333][333], ngrid[333][333];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
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
                ngrid[i][j] = grid[i][j];
            }
        }
        int curr, ci, cj, ni, nj;
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                deque<int> q;
                q.push_back(i * 500 + j);
                while (!q.empty()){
                    curr = q.front();
                    q.pop_front();
                    ci = curr / 500;
                    cj = curr % 500;
                    for (int k = 0; k < 4; ++k){
                        ni = ci + dx[k];
                        nj = cj + dy[k];
                        if (ni >= 0 and ni < r and nj >= 0 and nj < c){
                            if (ngrid[ci][cj] - 1 > ngrid[ni][nj]){
                                ngrid[ni][nj] = ngrid[ci][cj] - 1;
                                q.push_back(ni * 500 + nj);
                            }
                        }
                    }
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < r; ++i){
            for (int j = 0; j < c; ++j){
                // cout << ngrid[i][j] << ' ';
                res += ngrid[i][j] - grid[i][j];
            }
            // cout << endl;
        }
        cout << "Case #" << ncase << ": " ;
        cout << res << endl;

    }
    
    return 0;
}