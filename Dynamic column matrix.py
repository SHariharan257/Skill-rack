n, m = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(n)]
dp = [mat[i][0] for i in range(n)]
for j in range(1, m):
    mx1 = max(dp)
    idx = dp.index(mx1)
    mx2 = -1
    for i in range(n):
        if i != idx:
            mx2 = max(mx2, dp[i])
    new = [0] * n
    for i in range(n):
        if i != idx:
            new[i] = mat[i][j] + mx1
        else:
            new[i] = mat[i][j] + mx2
    dp = new
print(max(dp))
