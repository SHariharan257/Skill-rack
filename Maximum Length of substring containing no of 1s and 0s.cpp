#include <iostream>
#include <string>
#include <map>
using namespace std;
int maxLength(string s) {
    map<int, int> mp;
    int sum = 0;
    int ans = 0;
    mp[0] = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1')
            sum += 1;
        else
            sum -= 1;

        if (mp.count(sum)) {
            int len = i - mp[sum];

            if (len > ans)
                ans = len;
        }
        else {
            mp[sum] = i;
        }
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    cout << maxLength(s) << endl;
    return 0;
}
