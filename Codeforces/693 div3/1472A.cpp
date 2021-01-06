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
        int w, h, n;
        cin >> w >> h >> n;
        int cnt = 1;
        while (w % 2 == 0){
            w >>= 1;
            cnt *= 2;
        }
        while (h % 2 == 0){
            h >>= 1;
            cnt *= 2;
        }
        // cout << cnt << endl;
        if (cnt >= n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }
    return 0;
}