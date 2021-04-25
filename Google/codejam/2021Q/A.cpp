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

int main(){
    fast;
    int T;
    cin >> T;
    for (int ncase = 1; ncase <= T; ++ncase){
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        int res = 0;
        int l, idx, minval;
        for (int i = 1; i < n; ++i){
            l = i;
            idx = i;
            minval = a[i];
            for (int j = i + 1; j <= n; ++j){
                if (a[j] < minval){
                    minval = a[j];
                    idx = j;
                }
            }
            res += idx - i + 1;
            while (l < idx){
                swap(a[l], a[idx]);
                ++l;
                --idx;
            }

        }
        cout << "Case #" << ncase << ": " ;
        cout << res << endl;
    }
    return 0;
}