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
int dp[1111][2];
bool checkdup(int n, vector<int> a){
    vector<int> seen(n + 1, 0);
    for (auto num: a){
        seen[num] = 1;
    }
    int res = accumulate(seen.begin(), seen.end(), 0);
    return res == n + 1;
}
int cost(int n, vector<int> aa){
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        a[i] = aa[i];
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
    return res;
}
int main(){
    fast;
    int T;
    cin >> T;
    for (int ncase = 1; ncase <= T; ++ncase){
        bool flag = false;
        int n, c;
        cin >> n >> c;
        int mask = 1;
        for (int i = 0; i < n; ++i){
            mask *= n;
        }
        vector<int> a(n + 1, 0);
        // debug(n);
        // debug(mask);
        // cout << checkdup(4, {3, 1, 2, 1}) << endl;
        // cout << cost(4, {0, 4, 3, 2, 1}) << endl;
        for (int m = 0; m < mask; ++m){
            if (flag){
                break;
            }
            for(int i = 1; i <= n; ++i){
                a[i] = 0;
            }
            int mm = m;
            for (int k = 1; k <= n; ++k){
                a[k] = 1 + (mm % n);
                mm /= n;
            }
            // for(int i = 1; i <= n; ++i){
            //     cout << a[i] << " ";
            // }
            // cout << endl;
            // debug(checkdup(n, a));
            if (checkdup(n, a) == true){
                // debug(cost(n, a));
                if (cost(n, a) == c){
                    flag = true;
                    // cout << m << endl;
                }
            }
        }

        cout << "Case #" << ncase << ": " ;
        if (flag){
            for(int i = 1; i <= n; ++i){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}