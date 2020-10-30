#include <bits/stdc++.h>
const int maxn = 3005;
int dp[maxn][maxn];
int main(){
    std::string s, t, res;
    std::cin >> s >> t;
    int ls = s.length();
    int lt = t.length();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= ls; ++i){
        for (int j = 1; j <= lt; ++j){
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]){
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    int i = ls; 
    int j = lt;
    while (i > 0 and j > 0){
        if (s[i-1] == t[j-1]){
            res.push_back(s[i-1]);
            i -= 1;
            j -= 1;
        }
        else if (dp[i][j] == dp[i-1][j])
            i -= 1;
        else
            j -= 1;
        
    }
    std::reverse(res.begin(), res.end());
    std::cout << res;
    return 0;

}