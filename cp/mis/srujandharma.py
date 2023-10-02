n, m = map(int, input().split())
a = []
done = []

# def marker(i, j):
#     if i < 0 or i >= n or j < 0 or j >= m or a[i][j] == 0 or done[i][j]:
#         return

#     done[i][j] = 1
#     marker(i + 1, j)
#     marker(i - 1, j)
#     marker(i, j + 1)
#     marker(i, j - 1)

def uporleft(i, j):
    if i == 0 or j == 0:
        if i==j:
            return 1
        if i==0:
            return a[i][j-1]==0
        if j==0:
            return a[i-1][j]==0
    return a[i-1][j] == 0 and a[i][j-1] == 0

for i in range(n):
    row = list(map(int, input().split()))
    a.append(row)

# for i in range(n):
#     done.append([0] * m)
# print(a)
c = 0
for i in range(n):
    for j in range(m):
        if a[i][j]!=0 and uporleft(i, j):
            c += 1
print(c)
