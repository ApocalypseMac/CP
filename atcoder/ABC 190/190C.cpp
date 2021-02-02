#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int n, m, k, res = 0, cnt;
    cin >> n >> m;
    vector<int> a(m), b(m), state(n + 1, 0);
    for (int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
    }
    cin >> k;
    vector<int> c(k), d(k);
    for (int i = 0; i < k; ++i){
        cin >> c[i] >> d[i];
    }
    for (int i = 0; i < (1 << k); ++i){
        cnt = 0;
        for (int j = 0; j <= n; ++j){
            state[j] = 0;
        }
        for (int s = 0; s < k; ++s){
            if (i >> s & 1){
                state[d[s]] += 1;
            }
            else{
                state[c[s]] += 1;
            }
        }
        // for (int j = 0; j <= n; ++j){
        //     cout << state[j] << ' ';
        // }
        for (int j = 0; j < m; ++j){
            if (state[a[j]] and state[b[j]]){
                ++cnt;
            }
        }
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}