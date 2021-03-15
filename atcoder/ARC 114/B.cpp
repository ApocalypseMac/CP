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
// dsu
int p[200005];
int find(int i){
    if (p[i] != i)
        p[i] = find(p[i]);
    return p[i];
}
bool unionSet(int i, int j){
    int pi = find(i), pj = find(j);
    if (pi != pj){
        if (pi < pj){
            swap(pi, pj);
        }
        p[pi] = pj;
        return true;
    }
    else
        return false;
}
int main(){
    fast;
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    for (int i = 0; i < n; ++i){
        cin >> f[i+1];
        p[i+1] = i + 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (!unionSet(i, f[i])){
            ++cnt;
        }

    }
    int res = pow(2, cnt, MOD);
    --res;
    if (res < 0){
        res += MOD;
    }
    // if (cnt){
    //     cout << res << '\n';
    // }
    // else{
    //     cout << "0\n";
    // }
    cout << res << '\n';
    return 0;
}