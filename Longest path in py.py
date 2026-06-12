def dfs(i, j):
    if dp[i][j] != -1:
        return dp[i][j]
    ans = 1
    directions = [
        (1, 0),
        (-1, 0),
        (0, 1),
        (0, -1)
    ]
    for di, dj in directions:
        ni = i + di
        nj = j + dj

        if 0 <= ni < row and 0 <= nj < col and a[ni][nj] > a[i][j]:
            ans = max(ans, 1 + dfs(ni, nj))
    dp[i][j] = ans
    return ans
row, col = map(int, input().split())
a = []
for i in range(row):
    a.append(list(map(int, input().split())))
dp = [[-1 for _ in range(col)] for _ in range(row)]
res = 0
for i in range(row):
    for j in range(col):
        res = max(res, dfs(i, j))
print(res)
