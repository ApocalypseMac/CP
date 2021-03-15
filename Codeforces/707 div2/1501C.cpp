#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x) cout << #x << " is " << x << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
const int MOD = 1e9 + 7;
int s[5000005][2];

int main(){
    fast;
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i < n + 1; ++i){
        cin >> a[i];
    }
    int x;
    for (int i = 1; i < n + 1; ++i){
        for (int j = 1; j < i; ++j){
            x = a[i] + a[j];
            if (s[x][0] and s[x][1]){
                if (set{s[x][0], s[x][1], i, j}.size() == 4){
                    yes;
                    cout << s[x][0] << ' ' << s[x][1] << ' ' << i << ' ' << j << endl;
                    return 0;
                }
            }
            else{
                s[x][0] = i;
                s[x][1] = j;
            }
        }
    }
    no;
    return 0;
}