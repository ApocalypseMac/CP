#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        string s;
        cin >> s;
        int n = s.length();
        bool change[n] = {0};
        int res = 0;
        for (int i = 1; i < n - 1; ++i){
            if (s[i] == s[i-1] and change[i-1] == false and change[i] == false){
                change[i] = true;
            }
            if (s[i-1] == s[i+1] and change[i-1] == false){
                change[i+1] = true;
            }
        }
        if (n >= 2 and s[n-1] == s[n-2] and change[n-1] == false and change[n-2] == false){
            change[n-1] = true;
        }
        for (int i = 0; i < n; ++i){
            if (change[i]){
                ++res;
                //cout << " " << i << endl;
            }
                
        }
        cout << res << endl;
    }
    return 0;
}