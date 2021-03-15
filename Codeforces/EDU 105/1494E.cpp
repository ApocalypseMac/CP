#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << endl
#define check cout << "ok" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int n, m;
    cin >> n >> m;
    char q, c;
    int u, v, k;
    int same = 0, db = 0; // same: u -> v == v -> u, db: u <-> v both exist
    map<pair<int, int>, char> mp;
    for (; m > 0; --m){
        cin >> q;
        if (q == '+'){
            cin >> u >> v >> c;
            mp[{u, v}] = c;
            if (mp.count({v, u})){
                ++db;
                if (mp[{u, v}] == mp[{v, u}]){
                    ++same;
                }
            }
        }
        else if (q == '-'){
            cin >> u >> v;
            if (mp.count({v, u})){
                --db;
                if (mp[{u, v}] == mp[{v, u}]){
                    --same;
                }
            }
            mp.erase({u, v});
        }
        else{
            cin >> k;
            if (same or (db and k & 1)){
                yes;
            }
            else{
                no;
            }
        }


    }
    return 0;
}