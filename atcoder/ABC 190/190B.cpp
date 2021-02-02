#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int n, s, d, s1, d1;
    bool flag = false;
    cin >> n >> s >> d;
    for (int i = 0; i < n; ++i){
        cin >> s1 >> d1;
        if (s1 < s and d1 > d){
            flag = true;
        }
    }
    if (flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}