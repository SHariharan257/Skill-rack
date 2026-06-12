n, k, q = map(int, input().split())
arr = [0] * 200002
for _ in range(n):
    l, r = map(int, input().split())
    arr[l] += 1
    arr[r + 1] -= 1
for i in range(1, 200001):
    arr[i] += arr[i - 1]
pre = [0] * 200001
for i in range(1, 200001):
    pre[i] = pre[i - 1]
    if arr[i] >= k:
        pre[i] += 1
while q > 0:
    a, b = map(int, input().split())
    print(pre[b] - pre[a - 1])
    q -= 1
