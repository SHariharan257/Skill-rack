#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        int i, j;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans = "";
        i = n;
        j = m;
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                ans = s[i - 1] + ans;
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};
int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;
    Solution obj;
    string ans = obj.longestCommonSubsequence(s, t);
    cout << "\nLongest Common Subsequence: " << ans << endl;
    cout << "Length: " << ans.size() << endl;
    return 0;
}
