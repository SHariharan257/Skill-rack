#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int height[n];
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    int lh[n];
    int rh[n];
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (height[i] > mx)
            mx = height[i];
        lh[i] = mx;
    }
    mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (height[i] > mx)
            mx = height[i];
        rh[i] = mx;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mn;
        if (lh[i] < rh[i])
            mn = lh[i];
        else
            mn = rh[i];
        ans += mn - height[i];
    }
    cout << ans;
    return 0;
}
