#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        ll sum = 0LL;
        vector<int> a(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 2){
            cout << "NO" << endl;
        }
        else{
            vector<int> l(n + 2, -1), r(n + 2, -1);
            int li = 0, ri = n + 1;
            l[0] = 0;
            l[1] = a[0];
            while (li < n - 1){
                if (a[li+1] - l[li+1] >= 0){
                    l[li+2] = a[li+1] - l[li+1];
                    li += 1;
                }
                else{
                    break;
                }
            }
            r[n+1] = 0;
            r[n] = a[n-1];
            while (ri > 2){
                if (a[ri-3] - r[ri-1] >= 0){
                    r[ri-2] = a[ri-3] - r[ri-1];
                    ri -= 1;
                }
                else{
                    break;
                }
            }
            if (li == n - 1 and l[n] == 0){
                cout << "YES" << endl;
            }
            else{
                // for (int i = 0; i < n + 2; ++ i){
                //     cout << l[i] << " ";
                // }
                // cout << endl;
                // for (int i = 0; i < n + 2; ++ i){
                //     cout << r[i] << " ";
                // }
                // cout << endl;
                // cout << li << " " << ri << endl;
                bool flag = false;
                int aa, b, c, d;
                for (int i = 0; i < n - 1; ++i){
                    aa = l[i];
                    b = a[i];
                    c = a[i+1];
                    d = r[i+3];
                    if (aa >= 0 and d >= 0){
                        // cout << " " << i << " " << aa << " " << b << " " << c << " " << d << endl;
                        if ((b - aa == c - d && c - d >= 0) || (c - aa == b - d && b - d >= 0)){
                            flag = true;
                        }
                    }
                    if (flag){
                        break;
                    }
                }
                if (flag){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        
        }
    }
    return 0;
}