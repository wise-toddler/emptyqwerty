def solve():
    ans = []
    num = int(input())
    tmp = 1
    idx = 0
    print("num: ", num)
    num -= 1 # empty set
    while num >= tmp:
        num -= tmp
        tmp *= 2
        ans.append(idx)
        idx += 1
    # increasing sets donee
    print("num: ", num)
    # print()
    idx = 10000

    while num != 0:
        if num >= (2**idx):
            ans.append(idx)
            num -= 2**idx
        idx -= 1

    print(len(ans))
    for idx in ans:
        print(idx, end=' ')
    print()
    print()


t = int(input())

for _ in range(t):
    solve()
# 100000 = 32
# 100101 = 37
# 011111 = 31
#  00110 = 6
# 
# 11111  = 31
