#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for (; T > 0; --T){
        int n;
        cin >> n;
        vector<int> a(n, 0), premax(n, 0), sufmax(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        premax[0] = a[0];
        for (int i = 1; i < n; ++i)
            premax[i] = max(premax[i-1], a[i]);
        sufmax[n-1] = a[n-1];
        for (int i = n - 2; i >= 0; --i)
            sufmax[i] = max(sufmax[i+1], a[i]);
        // count frequency of max element
        // count = 3, mid one as the mid segment and output
        // count = 2, both as the begin and end of the mid segment
        // count = 1, the one as the initial mid segment
        int maxval = sufmax[0], count = 0;
        // cout << maxval << endl;
        vector<int> places;
        int x, y, midmin;
        for (int i = 0; i < n; ++i){
            if (a[i] == maxval){
                ++count;
                places.emplace_back(i);
            }
        }
        if (count >= 3){
            x = places[1] - 1;
            y = places[1] + 1;
            cout << "YES" << endl;
            cout << x + 1 << ' ' << y - x - 1 << ' ' << n - y << endl;
        }
        else {
            if (count == 1){
                x = places[0] - 1;
                y = places[0] + 1;
                midmin = a[places[0]];
            }
            else{
                x = places[0] - 1;
                y = places[1] + 1;
                midmin = a[places[0]];
                for (int i = x + 1; i < y; ++i){
                    midmin = min(midmin, a[i]);
                }
                // extend left and right bound greedily (optional)
                while (x >= 0 and a[x] > midmin)
                    x -= 1;
                while (y < n and a[y] > midmin)
                    y += 1;
            }
            bool flag = true;
            while (x >= 0 and y < n){
                if (midmin == premax[x] and midmin == sufmax[y]){
                    flag = false;
                    cout << "YES" << endl;
                    cout << x + 1 << ' ' << y - x - 1 << ' ' << n - y << endl;
                    break;
                }
                // extend left or right bound (choose larger one)
                // let u, v, w to be max(left), min(middle), max(right)
                // choose the move with the largest min(u, v, w)
                if (premax[x] > sufmax[y] or y == n - 1){
                    midmin = min(midmin, a[x]);
                    --x;
                }
                else if (premax[x] < sufmax[y] or x == 0){
                    midmin = min(midmin, a[y]);
                    ++y;
                }
                else{
                    if (premax[x-1] > sufmax[y+1]){
                        midmin = min(midmin, a[x]);
                        --x;
                    }
                    else if (premax[x-1] < sufmax[y+1]){
                        midmin = min(midmin, a[y]);
                        ++y;
                    }
                    else{
                        if (a[x] > a[y]){
                        midmin = min(midmin, a[x]);
                        --x;
                        }
                        else{
                            midmin = min(midmin, a[y]);
                            ++y;
                        }
                    }
                    
                }
                // cout << "x = " << x << "y = " << y << endl;
                // cout << premax[x] << midmin << sufmax[y] << endl;
            }
            if (flag)
                cout << "NO" << endl;
        }
    }
    return 0;
}