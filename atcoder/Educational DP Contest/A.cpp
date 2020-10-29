#include <bits/stdc++.h>
const int maxn = 100005;
int N, h[maxn], dp[maxn];
int main(){    
    std::cin >> N;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) std::cin >> h[i];
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < N; i++){
        dp[i] = std::min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }    
    std::cout << dp[N-1];
    return 0;
}