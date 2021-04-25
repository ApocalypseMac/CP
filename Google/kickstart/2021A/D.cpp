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
int a[555][555]; int b[555][555], r[555], c[555];
int main(){
    fast;
    int T;
    cin >> T;
    for (int ncase = 1; ncase <= T; ++ncase){
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                cin >> b[i][j];
            }
        }
        for (int i = 0; i < n; ++i){
            cin >> r[i];
        }
        for (int i = 0; i < n; ++i){
            cin >> c[i];
        }
        ll res = 0;

        cout << "Case #" << ncase << ": " ;
        cout << res << endl;

    }
    
    return 0;
}