#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        vector<int> a(n, 0);
        int maxval = 0;
        ll req = 0LL, sum = 0LL;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            sum += a[i];
            maxval = max(a[i], maxval);
        }
        ll mod = sum % (n - 1), div = sum / (n - 1);
        if (mod) div += 1;
        req = max(maxval * 1LL * (n - 1), div * (n - 1)) - sum;
        cout << req << endl;
    }
    return 0;
}