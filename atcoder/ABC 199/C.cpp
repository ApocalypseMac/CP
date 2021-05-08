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
    string s;
    cin >> s;
    vector<char> ss(2 * n);
    for (int i = 0; i < 2 * n; ++i){
        ss[i] = s[i];
    }
    int q;
    cin >> q;
    int flip = 0;
    int t, a, b;
    for (; q > 0; --q){
        cin >> t >> a >> b;
        if (t == 2){
            flip ^= 1;
        }
        else{
            a -= 1;
            b -= 1;
            if (flip){
                a += n;
                b += n;
                a %= 2 * n;
                b %= 2 * n;
            }
            swap(ss[a], ss[b]);
        }
    }
    if (flip){
        for (int i = 0; i < n; ++i){
            swap(ss[i], ss[i+n]);
        }
    }
    for (int i = 0; i < 2 * n; ++i){
        cout << ss[i];
    }
    cout << '\n';
    return 0;
}