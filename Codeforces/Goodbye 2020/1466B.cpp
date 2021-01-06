#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        int x[n] = {0};
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        int exist[2 * n + 2] = {0};
        for (int i = n - 1; i >= 0; --i){
            if (exist[x[i] + 1] == 0)
                exist[x[i] + 1] = 1;
            else
                exist[x[i]] = 1;
        }
        int res = 0;
        for (int i = 0; i < 2 * n + 2; ++i){
            if (exist[i])
                //cout << " " << i;
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}