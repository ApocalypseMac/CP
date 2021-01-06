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
        if (n == 1){
            int hh, ww;
            cin >> hh >> ww;
            cout << -1 << endl;
        }
        else{
            vector<vector<int>> h(n, vector<int> (3)); 
            int hh, ww;
            for (int i = 0; i < n; ++i){
                cin >> hh >> ww;
                if (hh > ww){
                    h[i][0] = ww;
                    h[i][1] = hh;
                }
                else{
                    h[i][0] = hh;
                    h[i][1] = ww;
                }
                h[i][2] = i + 1;
            }
            sort(h.begin(), h.end(), 
                [](const std::vector<int>& a, const std::vector<int>& b) {
                return a.at(1) < b.at(1);
                });
            // for (int i = 0; i < n; ++i){
            //     cout << h[i][0] << " " << h[i][1] << " " << h[i][2] << endl;
            // }
            vector<int> res(n + 1, -1);
            int p = -1, idx = -1, minw = 2e9;
            for (int i = 1; i < n; ++i){
                while (p + 1 < i and h[p+1][1] < h[i][1]){
                    ++p;
                    if (h[p][0] < minw){
                        idx = h[p][2];
                        minw = h[p][0];
                    }
                }
                if (minw < h[i][0]){
                    res[h[i][2]] = idx;
                }
                
            }
            for (int i = 1; i < n; ++i){
                cout << res[i] << " ";
            }
            cout << res[n] << endl;
        }
        
    }
    return 0;
}