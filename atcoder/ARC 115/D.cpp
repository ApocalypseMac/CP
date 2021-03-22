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
    int n, m;
    cin >> n >> m;
    vector<ll> res(n + 1, 0);
    res[0] = 1;



    for (int i = 0; i <= n; ++i){
        cout << res[i] << '\n';
    }
    return 0;
}