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
    int n, m;
    vector<ll> freq(22, 0);
    cin >> n >> m;
    int cnt;
    string s;
    for (int i = 0; i < n; ++i){
        cnt = 0;
        cin >> s;
        for (int j = 0; j < m; ++j){
            if (s[j] == '1'){
                ++cnt;
            }
        }
        ++freq[cnt % 2];
    }
    ll res = (ll)n * (n - 1) / 2;
    for (int i = 0; i < 2; ++i){
        res -= freq[i] * (freq[i] - 1) / 2;
    }
    cout << res << endl;
    return 0;
}