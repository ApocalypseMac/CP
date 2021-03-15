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
        string s;
        cin >> s;
        string res = "";
        int n = s.length();
        for (int i = 0; i < n; ++i){
            if (i % 2){ // Bob
                if (s[i] != 'z'){
                    res += 'z';
                }
                else {
                    res += 'y';
                }
            }
            else{ // Alice
                if(s[i] != 'a'){
                    res += 'a';
                }
                else{
                    res += 'b';
                }
            }
        }
        cout << res << endl;


    }
    return 0;
}