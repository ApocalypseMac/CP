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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (a[i]){
            ++cnt1;
        }
        else{
            ++cnt0;
        }
    }
    int t, idx;
    for (; q > 0; --q){
        cin >> t >> idx;
        if (t == 1){
            --idx;
            if (a[idx]){
                a[idx] = 0;
                ++cnt0;
                --cnt1; 
            }
            else{
                a[idx] = 1;
                ++cnt1;
                --cnt0;
            }
            // cout << cnt1 << cnt0 << endl;
        }
        
        else{
            if (idx <= cnt1){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}