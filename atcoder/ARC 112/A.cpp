#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        int l, r;
        cin >> l >> r;
        if (l > r / 2) {
            cout << 0 << endl;
        }
        else{
            ll res = 1LL * (r - 2 * l + 1) * (r - 2 * l + 2)/ 2;
            cout << res << endl;
            
        }
        

    }
    return 0;
}