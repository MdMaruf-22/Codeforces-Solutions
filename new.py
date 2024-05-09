MOD = 10**9 + 7

def max_sum_after_operations(t, test_cases):
    results = []
    for case in test_cases:
        n, k = case[0]
        a = case[1]
        
        prefix_sum = [0] * (n + 1)
        suffix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + max(0, a[i - 1])
        for i in range(n - 1, -1, -1):
            suffix_sum[i] = suffix_sum[i + 1] + max(0, a[i])
        
        max_sum = max(max(prefix_sum[i] + suffix_sum[i] for i in range(n)), 0)
        
        if k > 1:
            max_sum = max(max_sum, max(prefix_sum[i] + suffix_sum[i] + prefix_sum[i] * (k - 1) for i in range(1, n)))
            max_sum = max(max_sum, max(prefix_sum[i] + suffix_sum[i] + suffix_sum[i] * (k - 1) for i in range(n - 1)))
        
        results.append(max_sum % MOD)
    
    return results

# Sample Input
t = 12
test_cases = [
    [(2, 2), [-4, -7]],
    [(3, 3), [2, 2, 8]],
    [(1, 7), [7]],
    [(5, 1), [4, -2, 8, -12, 9]],
    [(7, 4), [8, 14, -9, 6, 0, -1, 3]],
    [(7, 100), [5, 3, -8, 12, -5, -9, 3]],
    [(6, 1000), [-1000000000, -1000000000, -1000000000, -1000000000, -1000000000, -1000000000]],
    [(2, 1), [1000000000, 8]],
    [(5, 4), [0, 0, 0, 0, 0]],
    [(6, 10), [48973, 757292, 58277, -38574, 27475, 999984]],
    [(7, 1), [-1000, 1000, -1000, 1000, -1000, 1000, -1000]],
    [(10, 10050), [408293874, -3498597, 7374783, 295774930, -48574034, 26623784, 498754833, -294875830, 283045804, 85938045]]
]

# Output
results = max_sum_after_operations(t, test_cases)
for res in results:
    print(res)
