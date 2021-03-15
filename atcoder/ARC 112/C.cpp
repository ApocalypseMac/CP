#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int pa[100005], num[100005], dp[100005][2]; 
// num: number of nodes in itself and subtrees
// dp: 0: first step in, 1: second step in
// 0: second get the coin, 1: first get the coin
vector<int> children[100005];
int dfs1(int i){
    int res = 1;
    for (auto next: children[i]){
        res += dfs1(next);
    }
    num[i] = res;
    return res; 
}

void dfs2(int i){
    dp[i][0] = 0;
    dp[i][1] = 1;
    for (auto next: children[i]){
        dfs2(next);
    }
    vector<int> evenbad; 
    vector<int> odd;
    // 0 determine the next
    for (auto next: children[i]){
        // cout << ' ' << next;
        if (num[next] % 2 == 0){ // not change order
            if (dp[next][0] >= dp[next][1]){ // positive
                dp[i][0] += dp[next][0];
                dp[i][1] += dp[next][1];
            }
            else{ // negative
                evenbad.emplace_back(next);
            }
            
        }
        else{ // change order
            odd.emplace_back(next);
        }
    }
    sort(odd.begin(), odd.end(), [&](int i, int j) {
        return (dp[i][0] - dp[i][1]) > (dp[j][0] - dp[j][1]);
        });
    // cout << ' ' << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    int turn = 0;
    for (auto c: odd){
        if (turn){
            dp[i][0] += dp[c][1];
            dp[i][1] += dp[c][0];
        }
        else{
            dp[i][0] += dp[c][0];
            dp[i][1] += dp[c][1];
        }
        turn ^= 1;
    }
    // cout << ' ' << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    for (auto c: evenbad){
        if (turn){
            dp[i][0] += dp[c][1];
            dp[i][1] += dp[c][0];
        }
        else{
            dp[i][0] += dp[c][0];
            dp[i][1] += dp[c][1];
        }
    }
    // cout << ' ' << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
}
int main(){
    fast;
    int n;
    cin >> n;
    pa[1] = 1;
    for (int i = 2; i <= n; ++i){
        cin >> pa[i];
        children[pa[i]].emplace_back(i);
    }
    dfs1(1);
    // for (int i = 1; i <= n; ++i){
    //     cout << ' ' << num[i];
    // }
    // for (int i = 1; i <= n; ++i){
    //     num[i] %= 2;
    // }
    dfs2(1);
    // for (int i = 1; i <= n; ++i){
    //     cout << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    // }
    cout << dp[1][1] << endl;
    return 0;
}