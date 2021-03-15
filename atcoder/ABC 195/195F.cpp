#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
const int MOD = 1e9 + 7;

int main(){
    fast;
    vector<ll> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    ll a, b;
    cin >> a >> b;
    vector<ll> dp(1048578, 0);
    dp[0] = 1;
    vector<int> state;
    int tmp;
    for (ll i = a; i <= b; ++i){
        tmp = 0;
        for (int j = 0; j < 20; ++j){
            if (i % prime[j] == 0){
                tmp |= (1 << j);
            }
        }
        // debug(tmp);
        state.push_back(tmp);
    }
    for (ll s: state){
        for (int i = 1048577; i >= 0; --i){
            if ((i & s) == s){
                dp[i] += dp[i^s];
            }
            
        }
    }
    ll res = accumulate(dp.begin(), dp.end(), 0LL);
    cout << res << endl;
    return 0;
}