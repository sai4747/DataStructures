# Backtracking — Cheat Sheet

When to use
- Generate combinations, permutations, subsets, and solve constraint-satisfaction problems (N-Queens, Sudoku).

Key points
- Use recursion with a path list; backtrack after exploring a choice.
- Prune early using constraints to reduce search space.

C++ Example (subsets)

```cpp
#include <vector>
using namespace std;

void dfs(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans){
    ans.push_back(cur);
    for (int i = idx; i < nums.size(); ++i){
        cur.push_back(nums[i]);
        dfs(i+1, nums, cur, ans);
        cur.pop_back();
    }
}
```

Python Example

```python
def subsets(nums):
    ans = []
    def dfs(i, cur):
        ans.append(cur[:])
        for j in range(i, len(nums)):
            cur.append(nums[j])
            dfs(j+1, cur)
            cur.pop()
    dfs(0, [])
    return ans
```
