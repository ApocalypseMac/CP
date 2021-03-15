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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    vector<int> mask(n);
    int msk;
    ll res = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        msk = 0;
        for (int j = 0; j < 15; ++j){
            if (a[i] % prime[j] == 0){
                msk |= (1 << j);
            }
        }
        mask[i] = msk;
    }
    // for (auto msk: mask){
    //     debug(msk);
    // }
    bool flag;
    ll tmp;
    for (int i = 0; i < (1 << 15); ++i){
        flag = true;
        for (auto msk: mask){
            if ((i & msk) == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            tmp = 1;
            for (int j = 0; j < 15; ++j){
                if ((i >> j) & 1){
                    tmp *= prime[j];
                }
            }
            res = min(res, tmp);
        }
    }
    cout << res << '\n';

    

    return 0;
}