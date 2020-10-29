#include <bits/stdc++.h>
typedef long long ll;
const int maxw = 100005, maxn = 105;
int N, W, weight[maxn], value[maxn];
ll dp[maxw];
int main(){
    std::cin >> N >> W;
    dp[0] = 0;
    for (int i = 0; i < N; i++){
        std::cin >> weight[i] >> value[i];
    }
    for (int i = 0; i < N; i++){
        for (int j = W; j >= weight[i]; j--){
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    std::cout << *std::max_element(std::begin(dp), std::end(dp));
    return 0;
}