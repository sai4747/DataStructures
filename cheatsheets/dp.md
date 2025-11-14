# Dynamic Programming — Cheat Sheet

When to use
- Problems with optimal substructure and overlapping subproblems (DP on arrays, strings, trees, intervals).

Key steps to design DP
1. Define state clearly (index, remaining capacity, last value, mask)
2. Find recurrence relation
3. Decide top-down (memo) or bottom-up (tabulation)
4. Initialize base cases and return the correct state

Common patterns
- 1D DP (prefix/suffix), 2D DP (strings, grids), state compression, bitmask DP

Pitfalls
- Incorrect state definition or missing dimensions
- Not handling base cases or off-by-one in transitions

Template (memoization)

```python
from functools import lru_cache

@lru_cache(None)
def dp(i, state):
    if base case: return
    ans = ...
    for choice in choices:
        ans = combine(ans, dp(next_i, next_state))
    return ans
```

Examples

C++ (Memoized Fibonacci)

```cpp
#include <vector>
using namespace std;

int fib(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int fib(int n) {
    vector<int> memo(n+1, -1);
    return fib(n, memo);
}
```

Python (Memoized Fibonacci)

```python
from functools import lru_cache

@lru_cache(None)
def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)
```
