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
        int n, m;
        cin >> n >> m;
        int r, c;
        vector<pair<int, int>> h(m);
        for (int i = 0; i < m; ++i){
            cin >> h[i].first >> h[i].second;
        }
        if (m % 2 == 1){
            cout << "NO" << endl;
        }
        else{
            sort(h.begin(), h.end(), 
                [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
                });
            // for (int i = 0; i < n; ++i){
            //     cout << grid[i][0] << " " << grid[i][1] << endl;
            // }
            bool flag = true;
            for (int i = 0; i * 2 < m; ++i){
                int r1 = h[2*i].first, c1 = h[2*i].second, r2 = h[2*i+1].first, c2 = h[2*i+1].second;
                if (2 * i + 2 < m){
                    int c3 = h[2*i+2].second;
                    if (c2 == c3){
                        flag = false;
                        cout << "NO" << endl;
                        break;
                    }
                }
                int odd = (r1 + c1 + r2 + c2) % 2;
                if (odd == 0){
                    flag = false;
                    cout << "NO" << endl;
                    break;
                }
            }
            if (flag){
                cout << "YES" << endl;
            }
        }
        
    }
    return 0;
}