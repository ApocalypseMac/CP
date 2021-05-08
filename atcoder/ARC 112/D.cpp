#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
// dsu
int p[2005];
int find(int i){
    if (p[i] != i)
        p[i] = find(p[i]);
    return p[i];
}
bool unionSet(int i, int j){
    int pi = find(i), pj = find(j);
    if (pi != pj){
        if (pi > pj){
            swap(pi, pj);
        }
        p[pi] = pj;
        return true;
    }
    else
        return false;
}
int main(){
    fast;
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h + w; ++i){
        p[i] = i;
    }
    unionSet(0, h - 1);
    unionSet(h - 1, h);
    unionSet(h, h + w - 1);
    string s;
    for (int i = 0; i < h; ++i){
        cin >> s;
        for (int j = 0; j < w; ++j){
            if (s[j] == '#'){
                // cout << ' ' << i << ' ' << j << endl;
                unionSet(i, h + j);
            }
        }
    }
    set<int> rows, columns;
    for (int i = 0; i < h; ++i){
        rows.insert(find(i));
        // cout << ' ' << find(i);
    }
    // cout << endl;
    for (int i = h; i < h + w; ++i){
        columns.insert(find(i));
        // cout << ' ' << find(i);
    }
    // cout << endl;
    int res = min(rows.size() - 1, columns.size() - 1);
    cout << res << endl;
    return 0;
}