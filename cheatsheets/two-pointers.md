# Two Pointers — Cheat Sheet

When to use
- Sorted arrays or when looking for pairs/subarrays with specific properties.
- Problems like two-sum variations on sorted arrays, container with most water, removing duplicates in-place.

Patterns
- Left/right pointers converge towards each other.
- Move left forward or right backward based on comparison with target.

Complexities
- Time: O(n) for single pass
- Space: O(1) (in-place)

Common pitfalls
- Off-by-one errors in while loops
- Handling duplicates correctly when asked to remove/skip

Example problems
- Two Sum II, Container With Most Water, 3Sum (use sorting + two pointers)

Examples

C++ (Container With Most Water — two-pointer pattern)

```cpp
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = (int)height.size() - 1;
    int best = 0;
    while (l < r) {
        int h = min(height[l], height[r]);
        best = max(best, h * (r - l));
        if (height[l] < height[r]) ++l;
        else --r;
    }
    return best;
}
```

Python (equivalent)

```python
def max_area(height):
    l, r = 0, len(height) - 1
    best = 0
    while l < r:
        area = min(height[l], height[r]) * (r - l)
        if area > best:
            best = area
        if height[l] < height[r]:
            l += 1
        else:
            r -= 1
    return best
```
