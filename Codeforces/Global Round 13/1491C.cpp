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
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        vector<int> s(n);
        set<int> st; // not 1
        for (int i = 0; i < n; ++i){
            cin >> s[i];
            if (s[i] != 1){
                st.insert(i);
            }
        }
        ll res = 0LL;
        int idx, tmp;
        for (int i = 0; i < n - 1; ++i){
            res += s[i] - 1;
            if (s[i] > n - 1 - i){
                
                s[i] = n - 1 - i;
            }
            while (s[i] > 1){
                idx = i;
                // cout << "  " << s[i] << endl;
                while (true){
                    tmp = s[idx];
                    --s[idx];
                    if (s[idx] == 1){
                        st.erase(idx);
                    }
                    auto it = st.lower_bound(idx + tmp);
                    if (it == st.end()){
                        break;
                    }
                    // cout << " " << *it << endl;
                    
                    idx = *it;
                }
                // for (int i = 0; i < n; ++i){
                //     cout << " " << s[i];
                // }
                // cout << endl;
            }
            // st.erase(i);
        }

        res += s[n-1] - 1;
        cout << res << endl;
    }
    return 0;
}