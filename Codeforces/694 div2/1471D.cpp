#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
const int maxa = 1000005;
int red[maxa] = {0};
int main(){
    fast;
    for (int i = 0; i < maxa; ++i){
        red[i] = i;
    }
    for (int i = 1000; i >= 2; --i){
        int sq = i * i;
        for (int i = 1; i <= maxa / sq; ++i){
            if (red[i*sq] % sq == 0){
                red[i*sq] /= sq;
            }
        }
    }
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        int a[n];
        int tmp;
        for (int i = 0; i < n; ++i){
            cin >> tmp;
            a[i] = red[tmp];
        }
        // for (int i = 0; i < n; ++i){
        //     cout << a[i] << " ";
        // }
        int res0 = 0, res1 = 0, res11 = 0;
        map<int, int> freq0;
        for (int i = 0; i < n; ++i){
            if (freq0.count(a[i])){
                ++freq0[a[i]];
            }
            else{
                freq0[a[i]] = 1;
            }
            res0 = max(res0, freq0[a[i]]);
        }
        for (const auto& n: freq0){
            if (n.first == 1){
                res11 = n.second;
            }
            else{
                if(n.second % 2 == 0){
                    res11 += n.second;
                }
                else{
                    res1 = max(res1, n.second);
                }
            }
        }
        res1 = max(res1, res11);
        int q;
        cin >> q;
        ll w;
        for (int i = 0; i < q; ++i){
            cin >> w;
            if (w == 0){
                cout << res0 << "\n";
            }
            else{
                cout << res1 << "\n";
            }
        }
    }
    return 0;
}