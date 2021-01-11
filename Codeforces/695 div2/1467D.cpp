#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int maxn = 5005;
const ll MOD = 1e9 + 7;
ll dp[maxn][maxn], mul[maxn];
int main(){
    fast;
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i){
        dp[0][i] = 1;
    }
    for (int i = 1; i <= k; ++i){
        for (int j = 0; j < n; ++j){
            if (j > 0){
                dp[i][j] += dp[i-1][j-1];
            }
            if (j < n - 1){
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= MOD;
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= k; ++j){
            mul[i] += dp[j][i] * dp[k-j][i];
            mul[i] %= MOD;
        }
    }
    // for (int i = 0; i < n; ++i){
    //     cout << " " << mul[i];
    // }
    // cout << endl;
    ll res = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        res += mul[i] * a[i];
        res %= MOD;
    }
    int idx, x;
    for (; q > 0; --q){
        cin >> idx >> x;
        --idx;
        res -= mul[idx] * a[idx];
        res %= MOD;
        a[idx] = x;
        res += mul[idx] * a[idx];
        res %= MOD;
        cout << (res + MOD) % MOD << endl; // need add mod
    }
    // cout << (-1LL % MOD) << endl; // expected -1
    return 0;
}