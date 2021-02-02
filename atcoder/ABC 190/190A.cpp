#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
int main(){
    fast;
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b){
        cout << "Takahashi" << endl;
    }
    else if (a < b){
        cout << "Aoki" << endl;
    }
    else if (c){
        cout << "Takahashi" << endl;
    }
    else{
        cout << "Aoki" << endl;
    }
    return 0;
}