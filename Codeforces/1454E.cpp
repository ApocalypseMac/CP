#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void calc(){
    int n;
    cin >> n;
    vector<int> degree(n + 1, 0);
    vector<unordered_set<int>> edges(n + 1);
    vector<int> num(n + 1, 1); // number of node in subtree
    deque<int> queue;
    ll res = 0LL;
    for (int i = 0; i < n; ++i){
        int u, v;
        cin >> u >> v;
        ++degree[u]; ++degree[v];
        edges[u].insert(v);
        edges[v].insert(u);
    }
    for (int i = 1; i <= n; ++i){
        if (degree[i] == 1){
            queue.emplace_back(i);
        }
    }
    while (!queue.empty()){
        int curr = queue.front();
        
        queue.pop_front();
        for (auto next : edges[curr]){
            --degree[curr]; --degree[next];
            edges[next].erase(curr);
            // edges[curr].erase(next);
            
            num[next] += num[curr];
            if (degree[next] == 1){
                queue.emplace_back(next);
            }
        }
        edges[curr].clear();
    }
    for (int i = 1; i <= n; ++i){
        if (degree[i] >= 1){
            res += num[i] * 1LL * (n - num[i]);
            res += num[i] * 1LL * (num[i] - 1) / 2;
        }
    }
    
    cout << res << endl;
}
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        calc();
    }
    return 0;
}