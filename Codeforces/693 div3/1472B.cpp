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
        int a1 = 0, a2 = 0;
        int tmp;
        for (int i = 0; i < n; ++i){
            cin >> tmp;
            if (tmp == 1){
                ++a1;
            }
            else{
                ++a2;
            }
        }
        if (a1 % 2 == 1){
            cout << "NO" << endl;
        }
        else if (a2 % 2 == 1 && a1 == 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }

    }
    return 0;
}