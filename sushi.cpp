#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(m);
    int i;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0;
    int count = 0;
    for (i = 0; i < n && j < m; i++) {
        if (b[j] <= 2 * a[i]) {
            count++;
            j++;
        }
    }
    cout << count << endl;
    return 0;
}
