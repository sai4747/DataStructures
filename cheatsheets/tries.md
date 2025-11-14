# Tries — Cheat Sheet

When to use
- Prefix queries, autocomplete, word search problems, dictionary operations.

C++ Example

```cpp
#include <array>
#include <string>
using namespace std;

struct TrieNode{
    array<TrieNode*,26> child{};
    bool end=false;
};

struct Trie{
    TrieNode* root=new TrieNode();
    void insert(const string &s){
        TrieNode* cur=root;
        for(char c:s){
            int i=c-'a';
            if(!cur->child[i]) cur->child[i]=new TrieNode();
            cur=cur->child[i];
        }
        cur->end=true;
    }
};
```

Python Example

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.end = True
```
