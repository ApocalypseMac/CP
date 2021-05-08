#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define flush cout.flush()
typedef long long ll;
const int MOD = 1e9 + 7;
ll dp[2000005]; // a1 <= n; a2 <= n; a1 + a2 <= k;
ll p[2000005]; // presum of dp[:i]


int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    k -= 1;
    ll res;
    ll l, r;
    for (ll i = 2; i <= 2 * n; ++i){
        res = 0;
        r = min(n, i - 1);
        l = max(1LL, i - n);
        if (r >= l){
            res = r - l + 1;
        }
        dp[i] = res;
        p[i] = p[i-1] + res;
    }
    // for (ll i = 0; i <= 3 * n; ++i){
    //     cout << ' ' << dp[i];
    // }
    // cout << endl;
    ll cnt;
    ll c, s2;
    for (ll s = 3; s <= 3 * n; ++s){
        l = max(2LL, s - n);
        r = min(2 * n, s - 1);
        if (r < l){
            continue;
        }
        // debug(s);
        // debug(l);
        // debug(r);
        cnt = p[r] - p[l-1];
        // debug(cnt);
        if (k >= cnt){
            k -= cnt;
        } 
        else{
            for (ll a = s - r; a <= s - l; ++a){
                if (k >= dp[s-a]){
                    k -= dp[s-a];
                }
                else{
                    s2 = s - a;
                    for (ll b = 1; b <= n; ++b){
                        c = s2 - b;
                        if (c >= 1 && c <= n){
                            if (k == 0){
                                cout << a << ' ' << b << ' ' << c << endl;
                                return 0;
                            }
                            k -= 1;
                        }
                    }
                }
            }
            
        }
    }
    return -1;
}