def dfs(g, i, j, r, c):
    if i < 0 or j < 0 or i >= r or j >= c or g[i][j] == '0':
        return
    g[i][j] = '0'
    dfs(g, i+1, j, r, c)
    dfs(g, i-1, j, r, c)
    dfs(g, i, j+1, r, c)
    dfs(g, i, j-1, r, c)
r, c = map(int, input().split())
g = [list(input()) for _ in range(r)]
ans = 0
for i in range(r):
    for j in range(c):
        if g[i][j] == '1':
            ans += 1
            dfs(g, i, j, r, c)
print(ans)
