#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int check(vector<int> a, vector<int> b){
    vector<int> overlap(1, 0);
    int m = a.size(), n = b.size();
    int tmp = 0;
    for (int i = 0; i < n; ++i){
        while (tmp < m and a[tmp] < b[i]){
            ++tmp;
        }
        if (tmp < m and a[tmp] == b[i]){
            overlap.emplace_back(a[tmp]);
            ++tmp;
        }
    }
    // for (auto x: a){
    //     cout << " " << x;
    // }
    // cout << endl;
    // for (auto x: b){
    //     cout << " " << x;
    // }
    // cout << endl;
    // for (auto x: overlap){
    //     cout << " " << x;
    // }
    // cout << endl;
    int k = overlap.size();
    int cnt = 0, res = 0, cnt1 = 0;
    int lb;
    for (int i = 0; i < n; ++i){
        while (cnt < m and a[cnt] <= b[i]){
            ++cnt;
        }
        while (cnt1 < k and overlap[cnt1] <= b[i]){
            ++cnt1;
        }
        lb = b[i] - cnt + 1;
        auto l = lower_bound(b.begin(), b.end(), lb);
        res = max(res, (k - cnt1) + i - (int) distance(b.begin(), l) + 1);
    }
    return res;
}
int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n, m;
        cin >> n >> m;
        vector<int> al(0), ar(0), bl(0), br(0);
        int tmp;
        for (int i = 0; i < n; ++i){
            cin >> tmp;
            if (tmp > 0){
                ar.emplace_back(tmp);
            }
            else{
                al.emplace_back(-tmp);
            }
        }
        for (int i = 0; i < m; ++i){
            cin >> tmp;
            if (tmp > 0){
                br.emplace_back(tmp);
            }
            else{
                bl.emplace_back(-tmp);
            }
        }
        reverse(al.begin(), al.end());
        reverse(bl.begin(), bl.end());
        int res = check(al, bl) + check(ar, br);
        cout << res << endl;
    }
    return 0;
}