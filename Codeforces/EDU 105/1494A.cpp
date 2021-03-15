#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
bool valid(string s){
    int res = 0;
    for (auto c: s){
        if (c == '('){
            ++res;
        }
        else{
            --res;
            if (res < 0){
                return false;
            }
        }
    }
    return res == 0;
}
int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        bool flag = false;
        string s;
        cin >> s;
        int a, b, c;
        for (int i = 0; i < 8; ++i){
            a = i & 1;
            b = (i >> 1) & 1;
            c = (i >> 2) & 1;
            string s1 = "";
            for (auto cc: s){
                if (cc == 'A'){
                    if (a){
                        s1 += '(';
                    }
                    else{
                        s1 += ')';
                    }
                }
                else if (cc == 'B'){
                    if (b){
                        s1 += '(';
                    }
                    else{
                        s1 += ')';
                    }
                }
                else{
                    if (c){
                        s1 += '(';
                    }
                    else{
                        s1 += ')';
                    }
                }
            }

            if (valid(s1)){
                flag = true;
                break;
            }
        }
        if (flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}