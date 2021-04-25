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
int b[111][111], res[111][111];
bool used[111][111], used1[111][111];
int n, m;

int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        cin >> n >> m;
        vector<pair<int, int>> arr(n * m);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cin >> b[i][j];
                arr[i*m+j] = {b[i][j], i * m + j};
                res[i][j] = 0;
                used[i][j] = false;
                used1[i][j] = false;
            }
        }
        sort(arr.begin(), arr.end());
        // for (int i = 0; i < m * n; ++i){
        //     cout << " " << i;
        // }
        // cout << endl;
        // for (int i = 0; i < m * n; ++i){
        //     cout << " " << b[i/m][i%m];
        // }
        // cout << endl;
        for (int i = 0; i < m; ++i){
            int x = arr[i].second / m, y = arr[i].second % m;
            used[x][y] = true;
            res[x][i] = b[x][y];
            used1[x][i] = true;
        }
        for (int i = 0; i < n; ++i){
            int idx = 0;
            for (int j = 0; j < m; ++j){
                if (used[i][j]){
                    continue;
                }
                while (idx < m and used1[i][idx]){
                    ++idx;
                }
                res[i][idx] = b[i][j];
                used[i][j] = true;
                used1[i][idx] = true;
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                cout << res[i][j] << ' ';
            }
            cout << endl;
        }

    }
    return 0;
}