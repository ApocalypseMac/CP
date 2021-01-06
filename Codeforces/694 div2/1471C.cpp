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
        int n, m;
        cin >> n >> m;
        vector<int> k(n + 1);
        vector<int> c(m + 1);
        for (int i = 1; i <= n; ++i){
            cin >> k[i];
        }
        for (int i = 1; i <= m; ++i){
            cin >> c[i];
        }
        sort(k.begin() + 1, k.end(), greater<int>());
        // for (int i = 1; i <= n; ++i){
        //     cout << " " << k[i];
        // }
        // for (int i = 1; i <= m; ++i){
        //     cout << " " << c[i];
        // }
        // cout << endl;
        ll res = 0LL;
        int i = 1, idx;
        while (i <= min(m, n)){
            // cout << i << " " << res << endl;
            idx = k[i];
            if (c[idx] > c[i]){
                res += c[i];
                ++i;
            }
            else{
                break;
            }
            
        }
        while (i <= n){
            idx = k[i];
            // cout << i << " " << res << endl;
            res += c[idx];
            ++i;
        }
        cout << res << endl;




    }
    return 0;
}