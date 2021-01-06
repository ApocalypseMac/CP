#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int maxn = 500005;
const int MOD = 1e9 + 7;
int m, n, k, u, v, t;
// dsu
int p[maxn];
int find(int i){
    if (p[i] != i)
        p[i] = find(p[i]);
    return p[i];
}
bool unionSet(int i, int j){
    int pi = find(i), pj = find(j);
    if (pi != pj){
        p[pi] = pj;
        return true;
    }
    else
        return false;
}
int main(){
    fast;
    int T = 1;
    // cin >> T;
    for (; T > 0; --T){
        cin >> n >> m;
        for (int i = 1; i <= m + 1; ++i){
            p[i] = i;
        }
        vector<int> res;
        for (int i = 1; i <= n; ++i){
            cin >> k;
            cin >> u;
            if (k == 1)
                v = m + 1;
            else
                cin >> v;
            if (unionSet(u, v)){
                res.push_back(i);
            }
        }
        t = 1;
        for (int i = 0; i < res.size(); ++i){
            t += t;
            t %= MOD;
        }
        cout << t << " " << res.size() << endl;
        for (auto i: res)
            cout << i << " ";
        cout << endl;

    }
    return 0;
}