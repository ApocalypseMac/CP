#include <bits/stdc++.h>
int N, M;
int main(){
    std::cin >> N >> M;
    std::vector<int> h(N), w(M);
    for (int i = 0; i < N; ++i){
        std::cin >> h[i];
    }
    for (int i = 0; i < M; ++i){
        std::cin >> w[i];
    }
    std::sort(h.begin(), h.end());
    std::sort(w.begin(), w.end());
    int psum[N + 1];
    psum[0] = psum[N] = 0;
    for (int i = 2; i < N; i += 2){
        psum[i] = psum[i-2] + h[i-1] - h[i-2];
    }
    for (int i = N - 2; i >= 0; i -= 2){
        psum[i] = psum[i+2] + h[i+1] - h[i];
    }
    int res = INT_MAX;
    for (int i = 0; i < M; ++i){
        auto index = std::lower_bound(h.begin(), h.end(), w[i]);
        if (index == h.end())
            res = std::min(res, psum[N-1] + w[i] - h[N-1]);
        else {
            int idx = index - h.begin();
            if (idx & 1) // pair with left one
                res = std::min(res, psum[idx-1] + w[i] - h[idx-1] + psum[idx]);
            else // pair with right one
                res = std::min(res, psum[idx] + h[idx] - w[i] + psum[idx+1]);
        }
    }
    std::cout << res;
    return 0;
}