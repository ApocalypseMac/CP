#include <bits/stdc++.h>
int N;
int gcd(int x, int y){
    y = abs(y);
    while (y){
        x %= y;
        std::swap(x, y);
    }
    return x;
}
bool line(int dx1, int dy1, int dx2, int dy2){
    if (dx1 == 0)
        return dx2 == 0;
    else if (dy1 == 0)
        return dy2 == 0;
    else if (dx2 == 0 or dy2 == 0)
        return false;
    else {
        int gcd1 = gcd(dx1, dy1);
        dx1 /= gcd1;
        dy1 /= gcd1;
        int gcd2 = gcd(dx2, dy2);
        dx2 /= gcd2;
        dy2 /= gcd2;
        return dx1 == dx2 and dy1 == dy2;
    }
}
int main(){
    std::cin >> N;
    std::vector<std::pair<int, int>> pos;
    for (int i = 0; i < N; ++i){
        int x, y;
        std::cin >> x >> y;
        pos.push_back(std::make_pair(x, y));
    }
    std::sort(pos.begin(), pos.end());
    // for (int i = 0; i < N; ++i){
    //     std::cout << pos[i].first << pos[i].second << std::endl;
    // }
    for (int i = 0; i < N - 2; ++i){
        int x1 = pos[i].first;
        int y1 = pos[i].second;
        for (int j = i + 1; j < N - 1; ++j){
            int x2 = pos[j].first;
            int y2 = pos[j].second;
            int dx1 = x2 - x1, dy1 = y2 - y1;
            for (int k = j + 1; k < N; ++k){
                int x3 = pos[k].first;
                int y3 = pos[k].second;
                int dx2 = x3 - x2, dy2 = y3 - y2;
                if (line(dx1, dy1, dx2, dy2)){
                    std::cout << "Yes";
                    return 0;
                }
            }
        }
    }
    std::cout << "No";
    return 0;
}