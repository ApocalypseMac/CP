#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        int cnt = 0;
        if (n > 65536)
            cnt = 4;
        else{
            for (int i = 4; i < n; i *= i)
                ++cnt;
        }
        cout << n - 1 + cnt << endl;
        int sq = 1 << (1 << cnt);
        int cnt1 = cnt, sq1;
        for (int i = n - 1; i > 2; --i){
            if (i == sq){
                --cnt1;
                sq = 1 << (1 << cnt1);
            }
            else{
                cout << i << ' ' << n << endl;
            }
        }
        sq = 1 << (1 << cnt);
        cout << n << ' ' << sq << endl;
        cout << n << ' ' << sq << endl;
        while (cnt){
            --cnt;
            sq1 = 1 << (1 << cnt);
            cout << sq << ' ' << sq1 << endl;
            cout << sq << ' ' << sq1 << endl;
            sq = 1 << (1 << cnt);
        }
    }
    return 0;
}