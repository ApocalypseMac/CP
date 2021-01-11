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
        vector<int> a(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        if (n <= 3){
            cout << 0 << endl;
        }
        else{
            int res = 0;
            int prev, l, r, delta = 0;
            for (int i = 1; i < n - 1; ++i){
                prev = 0;
                l = 0;
                r = 0;
                if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])){
                    ++res;
                    ++prev;
                }
                if (i > 1 and ((a[i-1] > a[i-2] && a[i-1] > a[i]) || (a[i-1] < a[i-2] && a[i-1] < a[i]))){
                    ++prev;
                    // cout << " 1" << endl;
                }
                if (i > 1 and ((a[i-1] > a[i-2] && a[i-1] > a[i+1]) || (a[i-1] < a[i-2] && a[i-1] < a[i+1]))){
                    ++r;
                }
                if (i < n - 2 and ((a[i+1] > a[i] && a[i+1] > a[i+2]) || (a[i+1] < a[i] && a[i+1] < a[i+2]))){
                    ++prev;
                    // cout << " 2" << endl;
                }
                if (i < n - 2 and ((a[i+1] > a[i-1] && a[i+1] > a[i+2]) || (a[i+1] < a[i-1] && a[i+1] < a[i+2]))){
                    ++l;
                }
                delta = max(delta, prev - l);
                delta = max(delta, prev - r);
                // cout << i << " " << delta << " " << prev << endl;
            }
            // bool flaglast = false, flaglast2 = false, flag2 = false, flag3 = false;
            // int res = 0;
            // for (int i = 1; i < n - 1; ++i){
            //     if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])){
            //         ++res;
            //         if (flaglast2){
            //             flag3 = true;
            //         }
            //         else if (flaglast){
            //             flag2 = true;
            //             flaglast2 = true;
            //         }
            //         flaglast = true;
            //     }
            //     else{
            //         flaglast = false;
            //         flaglast2 = false;
            //     }
            // }
            // if (res){
            //     --res;
            // }
            // if (flag2 and res){
            //     --res;
            // }
            // if (flag3 and res){
            //     --res;
            // }
            // cout << res << endl;
            cout << max(res - delta, 0) << endl;
        }
        

    }
    return 0;
}