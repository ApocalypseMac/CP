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
    int k;
    cin >> k;
    ll res = 0LL;
    ll ans;
    int i = 1;
    while (i * i * i <= k){ // a = b = c
        ++i;
    }
    res += i - 1;
    i = 1;
    while (i * i <= k){ // a = b
        ans = k / (i * i);
        if (ans >= i){
            --ans;
        }
        res += 3 * ans;
        ++i;
    }
    for (int c = 3; c <= k; ++c){
        int left = k / c;
        for (int b = 2; b <= min(left, c - 1); ++b){
            res += 6 * min(b - 1, left / b);
        }
    }
    cout << res << endl;


    return 0;
}