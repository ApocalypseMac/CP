#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define flush cout.flush()
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int n;
    cin >> n;
    vector<int> res(n + 1, 1); 
    set<int> prime;
    bool flag = false;
    int cnt, tmp;
    for (int i = 2; i <= n; ++i){
        cnt = 0;
        tmp = i;
        for (auto p: prime){
            while (tmp % p == 0){
                tmp /= p;
                ++cnt;
            }
            if (tmp == 1){
                break;
            }
        }
        if (tmp == i){
            ++cnt;
            prime.insert(tmp);
        }
        res[i] += cnt;
        // if (res[i] == 2){
        //     prime.insert(i);
        // }
    }
    for (int i= 1; i <= n; ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}