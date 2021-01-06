#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    ll res = 0LL;
    int d = n / 3, m = n % 3;
    res = 1LL * n * d - 3LL * d * (d + 1) / 2; // i is even
    //cout << "1 " << res << endl;
    res += 2 * d;
    //cout << "2 " << res << endl;
    res += 1LL * d * (d - 1);
    cout << res << endl;
    return 0;
}