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
            cout << "9" << endl;
        }
        else if (n == 2){
            cout << "98" << endl;
        }
        else{
            n -= 2;
            string s = "98";
            int cnt = 9;
            while (n){
                --n;
                s.push_back((char)('0' + cnt));
                ++cnt;
                if (cnt >= 10)
                    cnt -= 10;
                
            }
            cout << s << endl;
        }
        


    }
    return 0;
}