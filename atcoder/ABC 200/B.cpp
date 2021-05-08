#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define flush cout.flush()
typedef long long ll;
const int MOD = 1e9 + 7;

int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i){
        if (n % 200){
            n *= 1000;
            n += 200;
        }
        else{
            n /= 200;
        }
    }
    cout << n << endl;
    return 0;
}