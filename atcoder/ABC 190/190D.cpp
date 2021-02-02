#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    ll n;
    cin >> n;
    while (n % 2 == 0){
        n /= 2;
    }
    ll res = 2LL, cnt = 0LL;
    for (int i = 3; i < 1000005; ++i){
        cnt = 0LL;
        if (i > n){
            break;
        }
        while (n % i == 0){
            ++cnt;
            n /= i;
        }
        if (cnt){
            res *= (1LL + cnt);
        }
    }
    if (n != 1){
        res *= 2LL;
    }
    cout << res << endl;
    return 0;
}