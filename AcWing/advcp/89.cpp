#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
int main(){
    fast;
    int a, b, p;
    cin >> a >> b >> p;
    int res = 1 % p;
    for (; b; b >>= 1){
        if (b & 1) res = (ll) res * a % p;
        a = (ll) a * a % p;
    }
    cout << res;
    return 0;
}