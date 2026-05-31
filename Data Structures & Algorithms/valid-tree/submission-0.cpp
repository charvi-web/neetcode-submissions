class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }
    int findUP(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUP(parent[node]);
    }
    void unionBySize(int u, int v) {
        int upu = findUP(u);
        int upv = findUP(v);
        if (upu == upv)
            {return;}
        else if (size[upu] < size[upv]) {
            parent[upu] = upv;
            size[upv] += size[upu];
        } else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUP(u)==ds.findUP(v))
            return false;
            ds.unionBySize(u,v);
        }
        int components=0;
        for (int i=0;i<n;i++)
        {
            if (ds.findUP(i)==i) components++;
        }
        return components==1;
    }
};
