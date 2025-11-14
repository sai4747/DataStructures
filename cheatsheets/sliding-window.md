# Sliding Window — Cheat Sheet

When to use
- Problems asking for subarrays/substrings with constraints (sum, length, unique chars).
- Use fixed window for k-length problems, variable window for condition-based windows.

Patterns
- Expand right pointer to include elements until condition met; shrink left pointer to restore condition.
- Maintain window state (sum, counts, distinct count) with O(1) updates.

Complexities
- Time: O(n)
- Space: O(k) or O(1) depending on state

Pitfalls
- Off-by-one when measuring window size
- Properly updating counts when shrinking window

Template (variable window)

```python
l = 0
state = {}
for r in range(len(arr)):
    add arr[r] to state
    while window meets condition:
        # update answer
        remove arr[l] from state
        l += 1
```

Examples

C++ (Minimum Size Subarray Sum — variable window)

```cpp
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size(), l = 0, sum = 0, ans = INT_MAX;
    for (int r = 0; r < n; ++r) {
        sum += nums[r];
        while (sum >= s) {
            ans = min(ans, r - l + 1);
            sum -= nums[l++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
```

Python (minimum size subarray)

```python
def min_subarray_len(s, nums):
    l = 0
    total = 0
    ans = float('inf')
    for r, v in enumerate(nums):
        total += v
        while total >= s:
            ans = min(ans, r - l + 1)
            total -= nums[l]
            l += 1
    return 0 if ans == float('inf') else ans
```
