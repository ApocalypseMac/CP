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
    string s;
    cin >> s;
    int n = s.length();
    ll res = 0LL;
    // int sufcnt[n+1][26];
    // for (int i = 0; i <= n; ++i){
    //     for (int k = 0; k < 26; ++k){
    //         sufcnt[i][k] = 0;
    //     }
    // }
    // for (int i = n - 1; i >= 0; --i){
    //     for (int k = 0; k < 26; ++k){
    //         sufcnt[i][k] = sufcnt[i+1][k];
    //         if (s[i] - 'a' == k){
    //             ++sufcnt[i][k];
    //         }
    //     }
    // }
    vector<int> sufcnt(26, 0);
    for (int i = n - 1; i >= 0; --i){
        if (s[i] == s[i-1]){
            res += n - (i + 1);
            res -= sufcnt[s[i]-'a'];
            for (int k = 0; k < 26; ++k){
                sufcnt[k] = 0;
            }
            sufcnt[s[i]-'a'] = n - (i + 1);
        }
        ++sufcnt[s[i]-'a'];
    }
    // int i = n - 3;
    // char last = '#';
    // int lastidx = n;
    // while (i >= 0){
    //     if (s[i] == s[i+1] and s[i] != last){
    //         last = s[i];
    //         res += (n - (i + 2));
    //         // cout << ' ' << i << ' ' << res << endl;
    //         // cout << last - 'a' << endl;
    //         // cout << sufcnt[i+2][last-'a'] << ' ' << sufcnt[lastidx][last-'a'] << endl;
    //         res -= sufcnt[i+2][last-'a'] - sufcnt[lastidx][last-'a'];
    //         // cout << ' ' << i << ' ' << res << endl;
    //         lastidx = i;
    //     }
    //     else if (s[i] == s[i+1]){
    //         if (lastidx > i + 2){
    //             res += (lastidx - (i + 2));
    //             res -= sufcnt[i+2][last-'a'] - sufcnt[lastidx][last-'a'];
    //         }
    //         lastidx = i;
    //     }
        
    //     --i;
    //     // cout << ' ' << i << ' ' << res << endl;
    // }
    cout << res << endl;
    return 0;
}
