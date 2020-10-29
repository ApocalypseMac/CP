#include <bits/stdc++.h>
const int maxn = 100005;
int N, K, h[maxn], dp[maxn];
int main(){    
    std::cin >> N >> K;
    //memset(dp, INT_MAX, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < N; i++) std::cin >> h[i];
    for (int i = 1; i < N; i++){
        dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        for (int j = 2; j <= K and j <= i; j++){
            dp[i] = std::min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }    
    std::cout << dp[N-1];
    return 0;
}