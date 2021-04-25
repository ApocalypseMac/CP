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
int p[555], grid[555][555];

int main(){
    fast;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> p[i];
        grid[i][i] = p[i];
    }
    vector<int> a(0);
    for (int i = 0; i < n - 1; ++i){
        a.clear();
        for (int k = 0; k < n; ++k){
            if (p[k] >= n - i){
                a.emplace_back(p[k]);
            }
        }
        // for (auto x : a){
        //     cout << ' ' << x;
        // }
        // cout << endl;
        for (int j = 0; j <= i; ++j){
            grid[n-1-i+j][j] = a[j];
        }
        // for (int i = 0; i < n; ++i){
        //     for (int j = 0; j <= i; ++j){
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= i; ++j){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}