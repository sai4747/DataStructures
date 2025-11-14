# Union-Find (DSU) — Cheat Sheet

When to use
- Connectivity, components, Kruskal's MST, union-by-rank, cycle detection in undirected graphs.

C++ Example

```cpp
#include <vector>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { for (int i=0;i<n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if (a==b) return;
        if (r[a]<r[b]) swap(a,b);
        p[b]=a;
        if (r[a]==r[b]) r[a]++;
    }
};
```

Python Example

```python
class DSU:
    def __init__(self,n):
        self.p=list(range(n))
        self.r=[0]*n
    def find(self,x):
        while self.p[x]!=x:
            self.p[x]=self.p[self.p[x]]
            x=self.p[x]
        return x
    def unite(self,a,b):
        a=self.find(a); b=self.find(b)
        if a==b: return
        if self.r[a]<self.r[b]: a,b=b,a
        self.p[b]=a
        if self.r[a]==self.r[b]: self.r[a]+=1
```
