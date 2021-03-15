#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[n] = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> p0(1, 0), p1(1, 0);
    bool flag = false; // last: p0 F, p1 T
    for (int i = 0; i < n; ++i){
        if (a[i] == p0.back()){
            p1.emplace_back(a[i]);
            flag = true;
        }
        else if(a[i] == p1.back()){
            p0.emplace_back(a[i]);
            flag = false;
        }
        else if(flag){
            p0.emplace_back(a[i]);
            flag = false;
        }
        else{
            p1.emplace_back(a[i]);
            flag = true;
        }

        // if (flag0 and a[i] != p0.back()){
        //     p0.emplace_back(a[i]);
        // }
        // else if (flag1 and a[i] != p1.back()){
        //     p1.emplace_back(a[i]);
        // }
        // else{
        //     p0.emplace_back(a[i]);
        // }
    }
    p0.emplace_back(-1);
    p1.emplace_back(-1);
    int res = -2;
    for (int i = 1; i < p0.size(); ++i){
        if (p0[i] != p0[i-1]){
            ++res;
        }
    }
    for (int i = 1; i < p1.size(); ++i){
        if (p1[i] != p1[i-1]){
            ++res;
        }
    }
    // int res = 0, cnt = 1;
    // for (int i = 1; i < n + 1; ++i){
    //     if (a[i] == a[i-1]){
    //         ++cnt;
    //     }
    //     else{
    //         if (cnt == 1){
    //             res += 1;
    //         }
    //         else{
    //             res += 2;
    //         }
    //         cnt = 1;
    //     }
    // }
    cout << res << endl;
    return 0;
}