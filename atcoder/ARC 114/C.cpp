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
const int MOD = 998244353;
ll dp[5005][5005]; // i ** j % MOD 0 ** 0 == 1
ll p[5005]; // \sumi_1^m-1 i ** j % MOD
int pow(int a, int b, int p){
    int ans = 1 % p;
    for (; b; b >>= 1){
        if (b & 1) ans = (ll)ans * a % p;
        a = (ll) a * a % p;
    }
    return ans;
}

void init(int m, int n){
    for (int i = 0; i <= m; ++i){
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] = dp[i][j-1] * i % MOD;
        }
    }
    for(int j = 0; j <= n; ++j){
        // p[j] = 1;
        for (int i = 0; i < m; ++i){
            p[j] += dp[i][j];
            p[j] %= MOD;
        }
    }
    // for (int i = 0; i <= m; ++i){
    //     for(int j = 0; j <= n; ++j){
    //         cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
    //     }
    // }
    // for (int j = 0; j <= n; ++j){
    //     cout << j << ' ' << p[j] << '\n';
    // }
}

int main(){
    fast;
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    init(m, n);
    ll res = n * dp[m][n];
    res %= MOD;
    // debug(res);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            res -= dp[m][n-(i-j)-1] * p[i-j-1];
            res %= MOD;
            if (res < 0){
                res += MOD;
            }
            // cout << i << ' ' << j << ' ' << dp[m][n-(i-j)-1] << ' '  << p[i-j-1] << ' ' << res << '\n';
        }
    }
    cout << res << '\n';
    return 0;
}