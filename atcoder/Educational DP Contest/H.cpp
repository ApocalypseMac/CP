#include <bits/stdc++.h>
const int maxh = 1005;
const int mod = 1e9 + 7;
int h, w, dp[maxh][maxh];
std::string grid[maxh];
int main(){
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i){
        std::cin >> grid[i];
    }
    memset(dp, 0, sizeof(dp));
    if (grid[0][0] == '#' or grid[h-1][w-1] == '#'){
        std::cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < h; ++i){
        if (grid[i][0] == '.')
            dp[i][0] = dp[i-1][0];
    }
    for (int j = 1; j < w; ++j){
        if (grid[0][j] == '.')
            dp[0][j] = dp[0][j-1];
    }
    for (int i = 1; i < h; ++i){
        for (int j = 1; j < w; ++j){
            if (grid[i][j-1] == '.')
                dp[i][j] += dp[i][j-1];
            if (grid[i-1][j] == '.')
                dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
        }
    }
    std::cout << dp[h-1][w-1];
    return 0;
}