#include <iostream>
using namespace std;
class Solution {
public:
    int row, col;
    void dfs(char g[][100], int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col || g[i][j] == '0')
            return;
        g[i][j] = '0';
        dfs(g, i + 1, j);
        dfs(g, i - 1, j);
        dfs(g, i, j + 1);
        dfs(g, i, j - 1);
    }
    int solve(char g[][100], int r, int c) {
        row = r;
        col = c;
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (g[i][j] == '1') {
                    cnt++;
                    dfs(g, i, j);
                }
            }
        }
        return cnt;
    }
};
int main() {
    int row, col;
    cin >> row >> col;
    char g[100][100];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> g[i][j];
        }
    }
    Solution s;
    cout << s.solve(g, row, col);
    return 0;
}
