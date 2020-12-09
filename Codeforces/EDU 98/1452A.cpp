#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int a, b;
        cin >> a >> b;
        int res;
        if (a == b) res = a + b;
        else res = max(2 * a - 1, 2 * b - 1);
        cout << res << endl;
    }
    return 0;
}