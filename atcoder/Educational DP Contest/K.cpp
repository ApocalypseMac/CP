#include <bits/stdc++.h>
const int maxk = 100005;
int n, k;
bool dp[maxk];
int main(){
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        std::cin >> a[i];
    for (int i = 0; i <= k; ++i){
        dp[i] = false;
        for (int j = 0; j < n and a[j] <= i; ++j){
            // std::cout << j << std::endl;
            if (dp[i - a[j]] == false){
                dp[i] = true;
                // std::cout << i << dp[i] << std::endl;
                break;
            }
        }
    }
    if (dp[k])
        std::cout << "First";
    else
        std::cout << "Second";
    return 0;
}