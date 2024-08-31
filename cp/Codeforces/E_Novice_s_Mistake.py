# https://codeforces.com/contest/1992/problem/E
def count_valid_pairs(n):
    n_str = str(n)
    n_int = int(n)
    len_n = len(n_str)
    count = 0

    for a in range(1, 10001):
        correct_result = n_int * a
        s_len = len_n * a
        
        max_b = min(10000, correct_result)
        
        for b in range(1, max_b + 1):
            remaining_len = s_len - b
            num_repeats = remaining_len // len_n
            remainder = remaining_len % len_n
            
            if remainder == 0:
                string_result = n_int * num_repeats
            else:
                string_result = n_int * num_repeats + int(n_str[:remainder])
            
            if string_result == correct_result - b:
                count += 1

    return count

t = int(input())
for _ in range(t):
    n = int(input())
    count_valid_pairs(n)
