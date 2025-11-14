# Greedy Algorithms — Cheat Sheet

When to use
- Problems where a local optimum leads to a global optimum (interval scheduling, coin change with canonical denominations, selecting k smallest/largest).

Approach
- Prove greedy choice or use exchange argument
- Often sort by some key (end times, values per weight)

Pitfalls
- Greedy doesn't always work; validate with a proof or counterexample
- Watch for ties and stable sorting where necessary

Example problems
- Merge Intervals, Gas Station (useful to detect greedy fails), Jump Game

Examples

C++ (Merge Intervals)

```cpp
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
	if (intervals.empty()) return {};
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> res;
	res.push_back(intervals[0]);
	for (auto &iv : intervals) {
		if (iv[0] <= res.back()[1])
			res.back()[1] = max(res.back()[1], iv[1]);
		else
			res.push_back(iv);
	}
	return res;
}
```

Python (Merge Intervals)

```python
def merge(intervals):
	if not intervals: return []
	intervals.sort()
	res = [intervals[0]]
	for iv in intervals:
		if iv[0] <= res[-1][1]:
			res[-1][1] = max(res[-1][1], iv[1])
		else:
			res.append(iv)
	return res
```
