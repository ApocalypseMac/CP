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
        int u, v;
        cin >> u >> v;
        if (u > v){
            cout << "NO" << endl;
        }
        else{
            vector<int> ubit(40, 0);
            vector<int> vbit(40, 0);
            int cnt = 0;
            while (u){
                if (u % 2 == 1){
                    ++ubit[cnt];
                }
                u >>= 1;
                ++cnt;
            }
            cnt = 0;
            while (v){
                if (v % 2 == 1){
                    ++vbit[cnt];
                }
                v >>= 1;
                ++cnt;
            }
            int cnt1 = 0, cnt2 = 0;
            bool flag = true;
            for (int i = 0; i < 40; ++i){
                cnt1 += ubit[i];
                cnt2 += vbit[i];
                if (cnt1 < cnt2){
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}