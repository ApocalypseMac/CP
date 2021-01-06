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
        cin >> n;
        int a[n+1];
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        int dp[n+2] = {0};
        int curr;
        for (int i = 1; i <= n; ++i){
            curr = i + a[i];
            if (curr <= n){
                dp[curr] = max(dp[curr], dp[i] + a[i]);
            }
            else{
                dp[n+1] = max(dp[n+1], dp[i] + a[i]);
            }
        }
        cout << dp[n+1] << endl;
    }
    return 0;
}