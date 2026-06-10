#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int row, col;
    vector<vector<int> > dp;
    int dfs(vector<vector<int> >& a, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 1;
        int d[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        for (int k = 0; k < 4; k++) {
            int ni = i + d[k][0];
            int nj = j + d[k][1];
            if (ni >= 0 && ni < row &&
                nj >= 0 && nj < col &&
                a[ni][nj] > a[i][j]) {

                ans = max(ans, 1 + dfs(a, ni, nj));
            }
        }
        return dp[i][j] = ans;
    }
    int solve(vector<vector<int> >& a) {
        row = a.size();
        col = a[0].size();
        dp.assign(row, vector<int>(col, -1));
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res = max(res, dfs(a, i, j));
            }
        }
        return res;
    }
};
int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int> > a(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }
    Solution s;
    cout << s.solve(a);
    return 0;
}
