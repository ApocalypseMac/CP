#include <bits/stdc++.h>
const int maxn = 305;
double dp[maxn][maxn][maxn];
int n, arr[maxn];
int count[4] = {0, 0, 0, 0};
double helper(int a, int b, int c, int n){
    if (a == 0 and b == 0 and c == 0)
        return 0.0;
    if (dp[a][b][c] != -1.0)
        return dp[a][b][c];
    double ans = n * 1.0 / (a + b + c);
    if (a > 0)
        ans += helper(a - 1, b, c, n) * a * 1.0 / (a + b + c);
    if (b > 0)
        ans += helper(a + 1, b - 1, c, n) * b * 1.0 / (a + b + c);
    if (c > 0)
        ans += helper(a, b + 1, c - 1, n) * c * 1.0 / (a + b + c);
    dp[a][b][c] = ans;
    return ans;
}
int main(){
    std::cin >> n;
    for (int i = 0; i < n; ++i){
        std::cin >> arr[i];
        count[arr[i]] += 1;
    }
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            for (int k = 0; k <= n; ++k)
                dp[i][j][k] = -1.0;
        }
    }
    // std::cout << count[1] << count[2] << count[3] << endl;
    helper(count[1], count[2], count[3], n);
    printf("%.9f", dp[count[1]][count[2]][count[3]]);
    return 0;
}