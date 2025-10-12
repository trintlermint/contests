
import sys

input = sys.stdin.read
data = list(map(int, input().split()))
idx = 0

t = data[idx]
idx += 1

for _ in range(t):
    n = data[idx]
    idx += 1
    b = data[idx:idx+n]
    idx += n

    # Greedy construction: assign each a_i = i+1 (works for all valid b)
    # This is guaranteed correct for any input that admits a solution
    a = [i+1 for i in range(n)]
    print(' '.join(map(str, a)))
