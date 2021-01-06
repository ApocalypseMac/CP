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
        int n, x;
        cin >> n >> x;
        ll res = 0LL;
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = 1LL;
        }
        bool flag = true; 
        while (flag){
            for (int i = 0; i < n; ++i){
                if (a[i].first % x){
                    flag = false;
                    break;
                }
                else{
                    a[i].first /= x;
                    a[i].second *= x;
                    res += a[i].first * a[i].second;
                }
            }
        }
        for (int i = 0; i < n; ++i){
            res += a[i].first * a[i].second;
        }
        cout << res << endl;
    }
    return 0;
}