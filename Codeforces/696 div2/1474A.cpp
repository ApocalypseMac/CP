#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n, 0), b(n, 0), d(n, 0);
        for (int i = 0; i < n; ++i){
            b[i] = int(s[i]) - 48;
            d[i] = b[i];
        }
        a[0] = 1;
        d[0] += a[0];
        for (int i = 1; i < n; ++i){
            if (d[i] != d[i-1] - 1){
                a[i] = 1;
                d[i] += 1;
            }
        }
        for (int i = 0; i < n; ++i){
            cout << a[i];
        }
        cout << endl;

    }
    return 0;
}