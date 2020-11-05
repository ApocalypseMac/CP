#include <bits/stdc++.h>
int main(){
    long long res = 0LL;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i){
        int a, b;
        std::cin >> a >> b;
        res += 1LL * (a + b) * (b - a + 1) / 2;
    }
    std::cout << res;
    return 0;
}