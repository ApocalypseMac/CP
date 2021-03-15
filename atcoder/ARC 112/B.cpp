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
    ll b, c;
    cin >> b >> c;
    ll l1 = b - c / 2, r1 = b; // direct subtract
    ll l2 = -b - (c - 1) / 2, r2 = -b; // -1 then subtract
    r1 = b + (c - 2) / 2; // -1 then subtract then -1
    r2 = -b + (c - 1) / 2; // subtract then -1
    if (l1 > l2){ // l1 <= l2
        swap(l1, l2);
        swap(r1, r2);
    }
    if (r1 < l2){
        cout << r1 - l1 + 1 + r2 - l2 + 1 << endl;
    }
    else{
        cout << max(r1, r2) - l1 + 1 << endl;
    }

    
    
    return 0;
}