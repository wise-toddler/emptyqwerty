def solve():
    n = int(input())
    m = 10**9 + 7
    a = list(map(int, input().split()))
    a.sort()
    if a[0] == 1:
        i = 0
        while i < n and a[i] == 1:
            i += 1
        if i == n:
            return i
        if i == 1:
            ans = i + a[i]
        else:
            ans = i * a[i]
        ans %= m
        i += 1
        while i < n:
            ans = (ans * a[i]) % m
            i += 1
        return ans
    else:
        ans = 0
        for i in range(n):
            if i == 0:
                ans += a[i]
            else:
                ans = (ans * a[i]) % m
        return ans

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        print(solve())
