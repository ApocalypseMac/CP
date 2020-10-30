#include <bits/stdc++.h>
const int maxn = 3005;
int N;
long double p[maxn], dp[maxn][maxn];
int main(){
    std::cin >> N;
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= N; ++j){
            dp[i][j] = 0.0;
        }
    }
    dp[0][0] = 1.0;
    for (int i = 0; i < N; ++i)
        std::cin >> p[i];
    for (int i = 1; i <= N; ++i){
        dp[i][0] = dp[i-1][0] * (1 - p[i-1]);
        for (int j = 1; j <= i; ++j){
            dp[i][j] = dp[i-1][j] * (1 - p[i-1]) + dp[i-1][j-1] * p[i-1];
        }
    }
    long double res = 0;
    for (int i = N; 2 * i > N; --i){
        res += dp[N][i];
    }
    printf("%.9Lf", res); 
    // std::cout << std::fixed << std::setprecision(9) << res;
    return 0;
}