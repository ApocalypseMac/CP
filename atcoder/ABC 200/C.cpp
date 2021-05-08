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

int main(){
    fast;
    int n;
    cin >> n;
    vector<int> m(200, 0);
    int tmp;
    ll res = 0;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        m[tmp%200] += 1;
    }
    for (auto mm: m){
        if (mm > 1){
            res += (ll)mm * (mm - 1) / 2;
        }
    }
    cout << res << endl;
    return 0;
}