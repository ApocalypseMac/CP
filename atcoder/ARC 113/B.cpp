#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int pow(int a, int b, int p){
    int ans = 1 % p;
    for (; b; b >>= 1){
        if (b & 1) ans = (ll)ans * a % p;
        a = (ll) a * a % p;
    }
    return ans;
}
int main(){
    fast;
    int a, b, c;
    cin >> a >> b >> c;
    b = pow(b, c, 4);
    if (b == 0){
        b += 4;
    }
    a = pow(a, b, 10);
    cout << a << endl;
    // a %= 10;
    // b %= 4;
    // b
    // if (a == 0 or a == 1 or a == 5 or a == 6){
    //     cout << a << endl;
    // }
    // else if (a == 4 or a == 9){ // loop: 2
    //     b %= 2;
    //     if (b == 0){
    //         a *= a;
    //         a %= 10;
    //         cout << a << endl;
    //     }
    //     else{
    //         cout << a << endl;
    //     }
    // }
    // else{ // loop: 4
    //     b %= 4;
    //     c %= 4;
    //     if (c == 0){
    //         c += 4;
    //     }
    //     int b1 = 1;
    //     while (c){
    //         b1 *= b;
    //         --c;
    //     }
    //     b1 %= 4;
    //     if (b1 == 0){
    //         b1 += 4;
    //     }
    //     int a1 = 0;
    //     while (b1){
    //         a1 *= a;
    //         --b1;
    //     }
    //     cout << a << endl;
    // }
    return 0;
}