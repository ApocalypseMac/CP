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
    int amax = 0, bmin = 1000;
    int a, b;
    for (int i = 0; i < n; ++i){
        cin >> a;
        amax = max(amax, a);
    }
    for (int i = 0; i < n; ++i){
        cin >> b;
        bmin = min(bmin, b);
    }
    cout << max(0, bmin - amax + 1) << endl;
    return 0;
}