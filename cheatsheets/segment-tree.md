# Segment Tree — Cheat Sheet

When to use
- Range queries and point/range updates where O(log n) queries are required (sum, min, max).

C++ Example (simple segment tree for range sum)

```cpp
#include <vector>
using namespace std;

struct SegTree{
    int n; vector<int> tree;
    SegTree(int sz): n(sz), tree(4*sz,0) {}
    void build(int idx,int l,int r, const vector<int>& a){
        if(l==r){ tree[idx]=a[l]; return; }
        int m=(l+r)/2;
        build(idx*2,l,m,a); build(idx*2+1,m+1,r,a);
        tree[idx]=tree[idx*2]+tree[idx*2+1];
    }
};
```

Python: consider using iterative segment tree or Fenwick for simplicity.
