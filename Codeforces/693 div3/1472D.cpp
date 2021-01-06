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
        vector<ll> a(n, 0);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll sa = 0LL, sb = 0LL;
        for (int i = n - 1; i >= 0; --i){
            if ((n - i) % 2 and a[i] % 2 == 0){
                sa += a[i];
            }
            if ((n - i) % 2 == 0 and a[i] % 2){
                sb += a[i];
            }
        }
        // cout << sa << " " << sb << endl;
        if (sa == sb){
            cout << "Tie" << endl;
        }
        else if (sa > sb){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}