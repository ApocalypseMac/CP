#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define flush cout.flush()
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int dp[1111][2];
int main(){
    fast;
    int T;
    cin >> T;
    for (int ncase = 1; ncase <= T; ++ncase){
        int x, y;
        string s;
        cin >> x >> y >> s;
        int n = s.length();
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 1; i <= n; ++i){
            // 0: C 1: J
            dp[i][0] = INF;
            dp[i][1] = INF;
        }
        for (int i = 1; i <= n; ++i){
            if (s[i-1] == 'C'){
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
            }
            else if (s[i-1] == 'J'){
                dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
            }
            else{
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
                dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
            }
            if (i == 1){
                dp[i][0] = max(0, dp[i][0]);
                dp[i][1] = max(0, dp[i][1]);
            }
        }
        int res = min(dp[n][0], dp[n][1]);

        cout << "Case #" << ncase << ": " ;
        cout << res << endl;
    }
    return 0;
}