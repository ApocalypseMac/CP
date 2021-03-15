#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int query(int idx){
    cout << "? " << idx << endl;
    cout.flush();
    int val;
    cin >> val;
    return val;
}

int main(){
    fast;
    int n;
    cin >> n;
    vector<int> a(n + 2, INF);
    int l = 1, r = n;
    int mid = 0, val;
    while (l <= r){
        mid = l + (r - l) / 2;
        a[mid] = query(mid);
        if (a[mid] == 1){
            cout << "! " << mid << endl;
            return 0;
        }
        if (mid > 1){
            a[mid - 1] = query(mid - 1);
        }
        if (mid < n){
            a[mid + 1] = query(mid + 1);
        }
        if (a[mid] < a[mid + 1] && a[mid] < a[mid - 1]){
            cout << "! " << mid << endl;
            return 0;
        }
        else if (a[mid + 1] < a[mid - 1]){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    } 
    cout << "! " << mid << endl;
    return 0;
}