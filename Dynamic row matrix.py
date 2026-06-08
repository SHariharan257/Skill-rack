n, m = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(n)]
dp = mat[0][:]
for i in range(1, n):
    mx1 = max(dp)
    idx = dp.index(mx1)
    mx2 = -1
    for j in range(m):
        if j != idx:
            mx2 = max(mx2, dp[j])
    new = [0] * m
    for j in range(m):
        if j != idx:
             new[j] = mat[i][j] + mx1
        else:
            new[j] = mat[i][j] + mx2
    dp = new
print(max(dp))
