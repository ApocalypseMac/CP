#include <bits/stdc++.h>
int freq[10];
int lo, hi;
int main(){
    std::string s;
    std::cin >> s;
    for (auto ch : s){
        freq[ch - '0'] += 1;
    }
    if (s.size() == 1){
        lo = 1;
        hi = 1;
    }
    else if (s.size() == 2){
        lo = 2;
        hi = 12;
    }
    else {
        lo = 13;
        hi = 124;
    }
    for (int i = lo; i <= hi; ++i){
        int num = i * 8;
        int freq1[10] = {};
        while (num > 0){
            int mod = num % 10;
            freq1[mod] += 1;
            num /= 10;
        }
        bool flag = true;
        for (int j = 0; j < 10; ++j){
            if (freq[j] < freq1[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            std::cout << "Yes";
            return 0;
        }
    }
    std::cout << "No";
    return 0;
}