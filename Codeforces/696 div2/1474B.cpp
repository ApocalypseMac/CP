#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
bool isprime[40005];
void prime(){
    for (int i = 2; i < 40005; ++i){
        isprime[i] = true;
    }
    isprime[1] = false;
    for (int i = 2; i < 40005; ++i){
        if (isprime[i]){
            int j = 2 * i;
            while (j < 40005){
                isprime[j] = false;
                j += i;
            }
        }
    }
}
int main(){
    fast;
    prime();
    int T;
    cin >> T;
    for (; T > 0; --T){
        int d;
        cin >> d;
        int p, q;
        p = 1 + d;
        while(isprime[p] == false){
            ++p;
        }
        q = p + d;
        while (isprime[q] == false){
            ++q;
        }
        // cout << p << " " << q << endl;
        cout << p * q << endl;
    }
    return 0;
}