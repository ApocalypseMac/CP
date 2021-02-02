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
        vector<int> a(2*n);
        for (int i = 0; i < 2 * n; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool flag = false;
        vector<int> l(n, 0), r(n, 0);
        l[0] = a[2*n-1];
        for (int i = 0; i < 2 * n - 1; ++i){
            r[0] = a[i];
            multiset<int> m = {};
            for (int j = 0; j < 2 * n - 1; ++j){
                if (j != i){
                    m.insert(a[j]);
                }
            }
            int idx = 1, x = a[2*n-1];
            while (idx < n){
                auto itr = m.end();
                --itr;
                r[idx] = *itr;
                int vall = x - *itr;
                m.erase(itr);
                auto itl = m.find(vall);
                if (itl == m.end()){
                    break;
                }
                l[idx] = *itl;
                m.erase(itl);
                x = r[idx];
                ++idx;
            }
            if (idx == n){
                flag = true;
                break;
            }
        }
        if (flag){
            cout << "YES" << endl;
            cout << l[0] + r[0] << endl;
            for (int i = 0; i < n; ++i){
                cout << l[i] << " " << r[i] << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }


    }
    return 0;
}