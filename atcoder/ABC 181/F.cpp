#include <bits/stdc++.h>

struct UF{
    std::vector<int> p;
    std::vector<int> cnt;
    int n;

    UF(int size){
        n = size;
        p.resize(n);
        cnt.resize(n);
        for (int i = 0; i < n; ++i){
            p[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int x){
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    void unionSet(int x, int y){
        int px = find(x), py = find(y);
        if (px == py)
            return;
        if (cnt[px] < cnt[py])
            std::swap(px, py);
        p[py] = px;
        cnt[px] += cnt[py];
        return;
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

};

int main(){
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < N; ++i){
        int x, y;
        std::cin >> x >> y;
        points.push_back(std::make_pair(x, y));
    }
    std::sort(points.begin(), points.end());
    auto dis = [&](int i, int j) -> double{
        return sqrt(pow(points[i].first - points[j].first, 2.0) + pow(points[i].second - points[j].second, 2.0));
    };
    double l = 0.0, r = 1e3, eps = 1e-9;
    int up = N, bottom = N + 1;
    while (r - l > eps){
        double mid = l + (r - l) / 2;
        UF uf(N + 2);
        for (int i = 0; i < N; ++i){
            if (100 - points[i].second < mid)
                uf.unionSet(i, up);
            if (points[i].second + 100 < mid)
                uf.unionSet(i, bottom);
            for (int j = i + 1; j < N; ++j){
                if (dis(i, j) < mid)
                    uf.unionSet(i, j);
            }
        }
        if (uf.connected(up, bottom))
            r = mid;
        else 
            l = mid;

    }
    printf("%.9f", l / 2);
    return 0;
}