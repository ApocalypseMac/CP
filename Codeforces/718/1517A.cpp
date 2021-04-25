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
    ll maxval = 2050000000000000000;
    for (; T > 0; --T){
        ll n;
        cin >> n;
        int res = 0;
        for (ll x = maxval; x >= 2050; x /= 10){
            while (n >= x){
                n -= x;
                ++res;
            }
        }

        if (n == 0){
            cout << res << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}