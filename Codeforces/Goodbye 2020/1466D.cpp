#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        int w[n+1];
        for (int i = 1; i <= n; ++i)
            cin >> w[i];
        ll tmp = 0LL;
        for (int i = 1; i <= n; ++i)
            tmp += w[i];
        if (n > 2){
            int deg[n+1] = {0};
            int u, v;
            multiset<int> val = {};
            for (int i = 1; i < n; ++i){
                cin >> u >> v;
                if (deg[u])
                    val.insert(-w[u]);
                ++deg[u];
                if (deg[v])
                    val.insert(-w[v]);
                ++deg[v];
            }
            cout << tmp;
            for (auto it = val.begin(); it != val.end(); ++it){
                tmp -= *it;
                cout << " " << tmp;
            }
            cout << endl;
        }
        else{
            int u, v;
            cin >> u >> v;
            cout << tmp << endl;
        }
        
    }
    return 0;
}