#include <bits/stdc++.h>
typedef long long ll;
const int maxv = 100005, maxn = 105;
int N, W, weight[maxn], value[maxn], dp[maxv];
int main(){
    std::cin >> N >> W;
    dp[0] = 0;
    for (int i = 0; i < N; i++){
        std::cin >> weight[i] >> value[i];
    }
    for (int i = 1; i < maxv; i++)
        dp[i] = W + 1;
    // for (int i = 0; i < 20; i++){
    //     std::cout << dp[i] << std::endl;
    // }
    for (int i = 0; i < N; i++){
        for (int j = maxv - 1; j >= value[i]; j--){
            if (dp[j - value[i]] + weight[i] <= W){
                dp[j] = std::min(dp[j], dp[j - value[i]] + weight[i]);
            } 
            
        }
        //std::cout << dp[0] << std::endl;
    }
    // for (int i = 0; i < 20; i++){
    //    std::cout << dp[i] << std::endl;
    // }
    for (int i = maxv - 1; i >= 0; i--){
        if (dp[i] <= W){
            std::cout << i;
            return 0;
        }
    }
}