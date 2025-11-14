# Heaps & Priority Queues — Cheat Sheet

When to use
- Top-k problems, streaming median, merging sorted streams/lists.

Key points
- Use language-provided heap (C++: priority_queue, Python: heapq)
- For min-heap in C++ use greater comparator or push negatives

C++ Example (Kth largest)

```cpp
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : nums) {
        pq.push(x);
        if (pq.size() > k) pq.pop();
    }
    return pq.top();
}
```

Python Example

```python
import heapq

def find_kth_largest(nums, k):
    return heapq.nlargest(k, nums)[-1]
```
