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
const int INV2 = 5e8 + 4;

int pow(int a, int b, int p){
    // if b is ll one should let b = b % (p - 1)
    int ans = 1 % p;
    for (; b; b >>= 1){
        if (b & 1) ans = (ll)ans * a % p;
        a = (ll) a * a % p;
    }
    return ans;
}

int main(){
    fast;
    string s;
    ll n, k, q = 0;
    cin >> s;
    n = s.size();
    cin >> k;
    if (n * k == 1){ // s = '?', k = 1
        cout << 0 << endl;
        return 0;
    }
    vector<int> e(n);
    for (int i = 0; i < n; ++i){
        if (s[i] == '?'){
            ++q;
        }
        if (s[i] == '?' || s[(i+1)%n] == '?'){
            e[i] = INV2;
        }
        else{
            e[i] = 1 - (s[i] == s[(i+1)%n]);
        }
    }
    ll base = pow(2, (k * q) % (MOD - 1), MOD);
    // cout << base << endl;
    ll p = 0;
    for (int i = 0; i < n; ++i){
        p += k * e[i]; // last one: add 1 (if begin and end is diff)
        p %= MOD;
    }
    base *= p;
    base %= MOD;
    base *= INV2;
    base %= MOD;
    cout << base << endl;
    return 0;
}