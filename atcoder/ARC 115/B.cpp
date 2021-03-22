#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define flush cout.flush()
typedef long long ll;
const int MOD = 1e9 + 7;
int c[555][555];
int a[555], b[555];
int main(){
    fast;
    int n;
    cin >> n;
    int minval = 0x3f3f3f3f;
    int mini = -1, minj = -1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> c[i][j];
            if (c[i][j] < minval){
                minval = c[i][j];
                mini = i;
                minj = j;
            }
        }
    }
    for (int j = 0; j < n; ++j){
        a[j] = c[mini][j];
    }
    for (int i = 0; i < n; ++i){
        b[i] = c[i][0] - a[0];
        for (int j = 1; j < n; ++j){
            if (b[i] + a[j] != c[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i){
        cout << b[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}