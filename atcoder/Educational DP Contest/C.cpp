#include <bits/stdc++.h>
const int maxn = 100005;
int N, h[maxn][3], dp[maxn][3];
int main(){    
    std::cin >> N;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) 
        std::cin >> h[i][0] >> h[i][1] >> h[i][2];
    for (int i = 1; i <= N; i++){
        dp[i][0] = h[i][0] + std::max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = h[i][1] + std::max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = h[i][2] + std::max(dp[i-1][0], dp[i-1][1]);
    }    
    std::cout << *std::max_element(std::begin(dp[N]), std::end(dp[N]));
    return 0;
}