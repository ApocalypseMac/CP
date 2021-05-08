#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define flush cout.flush()
typedef long long ll;
const int MOD = 1e9 + 7;

int main(){
    fast;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> ss(200, -1);
    vector<int> b, c;
    int state;
    if (n < 8){
        state = 1 << n;
    }
    else{
        state = 222;
    }
    int mod, s1;
    for (int s = 1; s < state; ++s){
        mod = 0;

        for (int i = 0; i < 8; ++i){
            if ((s >> i) & 1){
                mod += a[i];
                mod %= 200;
            }
        }
        // debug(s);
        // debug(mod);
        if (ss[mod] != -1){
            s1 = ss[mod];
            for (int i = 0; i < 8; ++i){
                if ((s1 >> i) & 1){
                    c.emplace_back(i + 1);
                }
                if ((s >> i) & 1){
                    b.emplace_back(i + 1);
                }
            }
            yes;
            cout << b.size() << ' ';
            for (auto bb: b){
                cout << bb << ' ';
            }
            cout << endl;
            cout << c.size() << ' ';
            for (auto cc: c){
                cout << cc << ' ';
            }
            cout << endl;
            return 0;
        }
        ss[mod] = s;
    }
    no;
    return 0;
}