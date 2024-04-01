def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0] * (n+1) for _ in range(n+1)]
    s = [[0] * (n+1) for _ in range(n+1)]

    for l in range(2, n+1):
        for i in range(1, n-l+2):
            j = i + l - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

    return m, s

def print_optimal_parens(s, i, j):
    if i == j:
        print("A",i, end='')
    else:
        print("(", end='')
        print_optimal_parens(s, i, s[i][j])
        print_optimal_parens(s, s[i][j]+1, j)
        print(")", end='')

# Example usage:
p = [20,2,30,12,8]  # Kích thước của các ma trận
m, s = matrix_chain_order(p)
print(m)
print(s)
print(m[1])
print(len(p)-1)
print("Tổng số phép nhân tối thiểu là:", m[1][len(p)-1])
print("Cách nhóm ma trận tối ưu là:", end=' ')
print_optimal_parens(s, 1, len(p)-1)
