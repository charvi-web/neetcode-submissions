class DisjointSet
{
    vector<int>parent,rank,size;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        rank.resize(n+1,0);
        size.resize(n+1,1);
    }
    int findUP(int node)
    {
        if (node==parent[node])
        {
            return node;
        }
        return parent[node]=findUP(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int upu = findUP(u);
        int upv = findUP(v);
        if (upu==upv) return;
        if (rank[upu]<rank[upv])
        {
            parent[upu]=upv;
        }
        else if (rank[upu]>rank[upv])
        {
            parent[upv]=upu;
        }
        else
        {
            parent[upu]=upv;
            rank[upv]++;
        }
    }

    void unionBySize(int u,int v)
    {
        int upu = findUP(u);
        int upv = findUP(v);
        if (upu==upv) return;
        if (size[upu]<size[upv])
        {
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else
        {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUP(u)==ds.findUP(v))
            {
                return {u,v};
            }
            ds.unionByRank(u,v);

        }
return {};
    }
};
