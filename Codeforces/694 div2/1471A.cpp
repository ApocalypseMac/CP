#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        ll x;
        cin >> n >> x;
        ll s = 0LL, b = 0LL, a;
        for (int i = 0; i < n; ++i){
            cin >> a;
            b += (a - 1) / x + 1LL;   
            s += a;
        }
        cout << (s - 1) / x + 1LL << " " << b << endl;
    }
    return 0;
}