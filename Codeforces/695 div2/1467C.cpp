#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a1(n1), a2(n2), a3(n3);
    ll sum1 = 0LL, sum2 = 0LL, sum3 = 0LL, res = 0LL;
    for (int i = 0; i < n1; ++i){
        cin >> a1[i];
        sum1 += a1[i];
    }
    for (int i = 0; i < n2; ++i){
        cin >> a2[i];
        sum2 += a2[i];
    }
    for (int i = 0; i < n3; ++i){
        cin >> a3[i];
        sum3 += a3[i];
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(a3.begin(), a3.end());
    res = 2LL * (-a1[0] - a2[0]);
    res = max(res, 2LL * (-a1[0] - a3[0]));
    res = max(res, 2LL * (-a2[0] - a3[0]));
    res = max(res, -2LL * sum1);
    res = max(res, -2LL * sum2);
    res = max(res, -2LL * sum3);
    res += sum1 + sum2 + sum3;
    cout << res << endl;
    return 0;
}