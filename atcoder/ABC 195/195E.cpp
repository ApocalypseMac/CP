#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
const int MOD = 1e9 + 7;
int dp[200005][7];
int main(){
    fast;
    int n;
    cin >> n;
    string s, x;
    cin >> s >> x;
    // 1: Takahashi -1: Aoki
    for (int i = 0; i < 7; ++i){
        if (i){
            dp[n][i] = -1;
        }
        else{
            dp[n][i] = 1;
        }
    }
    int num, turn, mod1, mod2;
    for (int i = n - 1; i >= 0; --i){
        num = s[i] - '0';
        turn = x[i] == 'T' ? 1 : 0; // 1: Takahashi 0: Aoki
        for (int k = 0; k < 7; ++k){
            mod1 = (k * 10) % 7;
            mod2 = (mod1 + num) % 7;
            if (turn){ // T
                if (dp[i+1][mod1] == 1 or dp[i+1][mod2] == 1){
                    dp[i][k] = 1;
                }
                else{
                    dp[i][k] = -1;
                }
            } 
            else{ // A
                if (dp[i+1][mod1] == -1 or dp[i+1][mod2] == -1){
                    dp[i][k] = -1;
                }
                else{
                    dp[i][k] = 1;
                }
            }
        }
        
    }
    if (dp[0][0] == 1){
        cout << "Takahashi" << endl;
    }
    else{
        cout << "Aoki" << endl;
    }
    return 0;
}