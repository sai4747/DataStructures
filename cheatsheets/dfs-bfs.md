# DFS & BFS — Cheat Sheet

When to use
- Graph/tree traversal problems, connectivity, shortest path in unweighted graphs (BFS), exploring all paths (DFS).

BFS
- Use queue, level-order traversal
- Good for shortest path in unweighted graphs and multi-source BFS

DFS
- Use recursion or stack
- Good for backtracking, exploring components, topo sorts (with postorder)

Complexities
- Time: O(V + E)
- Space: O(V) for visited set / recursion stack

Pitfalls
- Stack depth for DFS (use iterative where recursion depth may be large)
- Remember to mark visited early to avoid cycles

Templates
- BFS: use deque from collections
- DFS recursive: define helper(node, parent)

Examples

C++ (BFS - Number of Islands)

```cpp
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
	if (grid.empty()) return 0;
	int m = grid.size(), n = grid[0].size(), cnt = 0;
	vector<int> dirs = {0,1,0,-1,0};
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '1') {
				++cnt;
				queue<pair<int,int>> q;
				q.push({i,j});
				grid[i][j] = '0';
				while (!q.empty()) {
					auto [x,y] = q.front(); q.pop();
					for (int d = 0; d < 4; ++d) {
						int nx = x + dirs[d], ny = y + dirs[d+1];
						if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1') {
							grid[nx][ny] = '0';
							q.push({nx,ny});
						}
					}
				}
			}
		}
	}
	return cnt;
}
```

Python (DFS recursive - Number of Islands)

```python
def num_islands(grid):
	if not grid: return 0
	m, n = len(grid), len(grid[0])
	def dfs(i, j):
		if i<0 or j<0 or i>=m or j>=n or grid[i][j]=='0':
			return
		grid[i][j] = '0'
		for di, dj in ((1,0),(-1,0),(0,1),(0,-1)):
			dfs(i+di, j+dj)
	cnt = 0
	for i in range(m):
		for j in range(n):
			if grid[i][j] == '1':
				cnt += 1
				dfs(i,j)
	return cnt
```
