#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int maxn = 500005;
const ll MOD = 1e9 + 7;
ll x[maxn];
int bitcnt[63];
int n, d, dm;
ll tmp, res, l, r;
ll m[63];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 63; ++i){
        m[i] = (1LL << i) % MOD;
    }
    int T;
    cin >> T;
    for (; T > 0; --T){
        // int n;
        cin >> n;
        // ll x[n];
        memset(bitcnt, 0, sizeof(bitcnt));
        // ll bitcnt[63] = {0LL};
        // int d;
        // int dm = 0;
        dm = 0;
        // ll tmp;
        for (int i = 0; i < n; ++i){
            d = 0;
            cin >> x[i];
            tmp = x[i];
            while (tmp){
                if (tmp & 1){
                    ++bitcnt[d];
                }
                ++d;
                tmp >>= 1;
            }
            dm = max(dm, d + 1);
        }
        // ll res = 0LL;
        res = 0LL;
        // for (int j = 0; j < 62; ++j){
        //     cout << bitcnt[j] << " ";
        // }
        // bool isone[dm] = {0};
        for (int i = 0; i < n; ++i){
            l = 0LL; r = 0LL;
            // cout <<  " "  << x[i] << " ";
            tmp = x[i];
            // memset(isone, 0, sizeof(isone));
            // d = 0;
            // while (tmp){
            //     if (tmp & 1){
            //         isone[d] = true;
            //     }
            //     ++d;
            //     tmp >>= 1;
            // }
            for (int j = 0; j < dm; ++j){
                if (tmp & 1){
                    l += bitcnt[j] * m[j];
                    r += n * m[j];
                }
                else{
                    r += bitcnt[j] * m[j];
                }
                tmp >>= 1;
                l %= MOD;
                r %= MOD;
            }
            res += l * r;
            res %= MOD;
            // cout << " " << l << " " << r << " " << res << endl;
        }
        cout << res << endl;
    }
    return 0;
}