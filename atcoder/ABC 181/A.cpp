#include <bits/stdc++.h>
int main(){
    int n;
    std::cin >> n;
    if (n & 1)
        std::cout << "Black";
    else
        std::cout << "White";
    return 0;
}