#include <bits/stdc++.h>
int n, m;
int main(){
    std::cin >> n >> m;
    std::vector<int> in(n + 1), len(n + 1, 0);
    std::vector<std::vector<int>> edges(n + 1);
    for (int i = 0; i < m; ++i){
        int x, y;
        std::cin >> x >> y;
        edges[x].push_back(y);
        in[y] += 1;
    }
    std::deque<int> queue;
    for (int i = 1; i <= n; ++i){
        if (in[i] == 0)
            queue.push_back(i);
    }
    while (!queue.empty()) {
        int curr = queue.front();
        // std::cout << curr << in[curr] << len[curr] << std::endl;
        for (auto next: edges[curr]){
            in[next] -= 1;
            if (in[next] == 0){
                len[next] = len[curr] + 1;
                queue.push_back(next);
            }
        }
        queue.pop_front();
    }
    for (int i = 1; i <= n; ++i){
        // std::cout << len[i] << std::endl;
    }
    std::cout << *std::max_element(len.begin(), len.end());
    return 0;
    

}