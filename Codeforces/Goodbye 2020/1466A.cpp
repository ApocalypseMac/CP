#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        int a[n] = {0};
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int d[101] = {0};
        int diff;
        for (int i = 1; i < 101; ++i){
            d[i] = 0;
        }
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                diff = a[i] - a[j];
                if (d[diff] == 0){
                    d[diff] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 1; i < 101; ++i){
            if (d[i]){
                ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}