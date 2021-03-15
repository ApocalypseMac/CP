#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main(){
    fast;
    int T;
    cin >> T;
    int n, u, v, temp1, temp2;
    int res;
    for (; T > 0; --T){
        cin >> n >> u >> v;
        vector<int> col(n);
        int mx = -INF, mn = INF;
        for (int i = 0; i < n; ++i){
            cin >> col[i];
            mx = max(col[i], mx);
            mn = min(col[i], mn); 
        }
        res = 1;
        for (int i = 0; i < n - 1; ++i){
            // temp1 = col[i];
            // temp2 = col[i+1];
            // if (temp1 < temp2){
            //     swap(temp1, temp2);
            // }
            // if (temp1 == temp2){
            //     res = min(res, u + v);
            //     res = min(res, 2 * v);
            // }
            // else if (temp1 == temp2 + 1){
            //     res = min(res, u);
            //     res = min(res, v);
            // }
            // else{
            //     res = 0;
            //     break;
            // }
            if (abs(col[i] - col[i+1]) > 1){
                res = 0;
                break;
            }
        }
        if (res){
            if (mx != mn){
                res = min(u, v);
            }
            else{
                res = min(u + v, v + v);
            }
        }
        cout << res << endl;
    }
    return 0;
}