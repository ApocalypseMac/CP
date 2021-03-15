#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        // cout << T << endl;
        int n;
        vector<int> color(8, 0);
        vector<int> mxdiag(8, 0);
        vector<int> mndiag(8, 0);
        vector<int> d(8, 0);
        cin >> n;
        for (int i = 0; i < 4; ++i){
            cin >> color[i];
            if (color[i] > n - 2){
                mndiag[i] = color[i] - n + 2;
            }
            mxdiag[i] = min(color[i], 2);
            color[i+4] = color[i];
            mxdiag[i+4] = mxdiag[i];
            mndiag[i+4] = mndiag[i];
        }
        // for (int i = 0; i < 8; ++i){
        //     cout << " " << color[i];
        // }
        // cout << endl;
        // for (int i = 0; i < 8; ++i){
        //     cout << " " << mxdiag[i];
        // }
        // cout << endl;
        // for (int i = 0; i < 8; ++i){
        //     cout << " " << mndiag[i];
        // }
        // cout << endl;
        bool flag = false;
        for(int i = 0; i < 16; ++i){
            for (int k = 0; k < 4; ++k){
                d[k] = (i >> k) % 2;
                d[k+4] = d[k];
            }
            
            bool flag1 = true;
            for (int k = 0; k < 4; ++k){
                if (d[k] + d[k+1] > mxdiag[k] or d[k] + d[k+1] < mndiag[k]){
                    flag1 = false;
                }
            }
            // cout << i;
            // for (int i = 0; i < 8; ++i){
            //     cout << " " << d[i];
            // }
            // cout << flag1 << endl;
            flag |= flag1;
        }
        if (flag){
            yes;
        }
        else{
            no;
        }
    }
    return 0;
}