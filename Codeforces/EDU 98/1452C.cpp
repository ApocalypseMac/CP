#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        string s;
        cin >> s;
        int cnt1 = 0, cnt2 = 0, res = 0;
        for (auto c : s){
            if (c == '('){
                cnt1 += 1;
            }
            else if (c == '['){
                cnt2 += 1;
            }
            else if (c == ')'){
                if (cnt1){
                    cnt1 -= 1;
                    res += 1;
                }
            }
            else{
                if (cnt2){
                    cnt2 -= 1;
                    res += 1;
                }
            }
        }
        cout << res << endl;
    }
    return 0;

}