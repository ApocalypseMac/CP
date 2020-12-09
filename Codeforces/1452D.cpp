#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll madd(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll mmul(ll a, ll b){
    return (a % MOD * b % MOD) % MOD;
}

ll mpow(ll a, int b){
    ll res = 1LL;
    while (b){
        if (b & 1) res = mmul(res, a);
        a = mmul(a, a);
        b /= 2;
    }
    return res;
}

ll minv(ll a){
    return mpow(a, MOD - 2);
}

int main(){
    int n;
    cin >> n;
    vector<ll> dp(n + 1, 0LL);
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i)
        dp[i] = madd(dp[i-1], dp[i-2]);
    ll res;
    res = mmul(dp[n], minv(mpow(2LL, n)));
    cout << res << endl;
    return 0;

}