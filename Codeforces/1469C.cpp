#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n, k;
        cin >> n >> k;
        int h[n] = {0}, hi[n] = {0}, lo[n] = {0}; // lowest and highest possible height of lower bound
        for (int i = 0; i < n; ++i)
            cin >> h[i];
        hi[0] = h[0];
        lo[0] = h[0];
        bool flag = true;
        int ll, hh;
        for (int i = 1; i < n; ++i){
            ll = max(h[i], lo[i-1] + 1 - k);
            hh = min(h[i] + k - 1, hi[i-1] + k - 1);
            if (ll > hh){
                cout << "NO" << endl;
                flag = false;
                break;
            }
            lo[i] = ll;
            hi[i] = hh;
        }
        if (flag){
            if (lo[n-1] > h[n-1] or h[n-1] > hi[n-1]){
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}