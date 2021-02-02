#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int n;
    ll res = 0LL;
    cin >> n;
    vector<int> a(n), b(n);
    ordered_set<int> s;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        res += i - s.order_of_key(a[i]);
        s.insert(a[i]);
    }
    cout << res << endl;
    for (int i = 1; i < n; ++i){
        res += (n - 1 - a[i-1]) - a[i-1];
        cout << res << endl;
    }
    return 0;
}