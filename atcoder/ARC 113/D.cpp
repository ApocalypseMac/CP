#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 998244353;
int pow(int a, int b, int p){
    int ans = 1 % p;
    for (; b; b >>= 1){
        if (b & 1) ans = (ll)ans * a % p;
        a = (ll) a * a % p;
    }
    return ans;
}
int main(){
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    ll res = 0LL;
    ll tmp = 0LL, tmp2 = 0LL;
    if (m == 1 or n == 1){
    //     cout << k << endl;
    // }
    // else if (m == 1){ // b = max(A)
    //     res = pow(k, n, MOD);
    //     cout << res << endl;
    // }
    // else if (n == 1){ // a = min(b)
        res = pow(k, m * n, MOD);
        cout << res << endl;
    }
    else {
        // min(B) >= max(A)
        for (int i = 1; i <= k; ++i){ // min(B)
            tmp = 1LL * pow(i, n, MOD); // a ways
            tmp2 = 1LL * (pow((k + 1 - i), m, MOD) - pow((k - i), m, MOD));
            if (tmp2 < 0){
                tmp2 += MOD;
            }
            // cout << ' ' << tmp << endl;
            // cout << ' ' << tmp2 << endl;
            res += tmp * tmp2;
            res %= MOD;
            // cout << ' ' << res << endl;
        }
        cout << res << endl;
    }
    return 0;
}