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
        ll a, b, n;
        cin >> a >> b >> n;
        vector<ll> aa(n), bb(n);
        int mxidx = 0;
        ll mx = 0;
        for (int i = 0; i < n; ++i){
            cin >> aa[i];
            if (aa[i] > mx){
                mx = aa[i];
                mxidx = i;
            }
        }
        // cout << " " << mxidx << endl;
        for (int i = 0; i < n; ++i){
            cin >> bb[i];
        }
        ll time, dmg;
        bool flag = true;
        for (int i = 0; i < n; ++i){
            if (i != mxidx){ // not last
                time = (bb[i] - 1) / a + 1;
                dmg = aa[i] * time;
                if (dmg >= b){
                    flag = false;
                    cout << "NO" << endl;
                    break;
                }
                b -= dmg;
            }
        }
        if (flag){
            time = (bb[mxidx] - 1) / a + 1;
            if (aa[mxidx] * (time - 1) >= b){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }


    }
    return 0;
}