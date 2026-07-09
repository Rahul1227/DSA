class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int u) {
        if (parent[u] == u) {
            return u;
        }

        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if (parentU == parentV)
            return;

        if (size[parentU] >= size[parentV]) {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        } else {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }

    bool isConnected(int u, int v) {
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        return parentU == parentV;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        DisjointSet ds(n);
        // vector<vector<int>> adj(n);
        int i = 0;
       
            for (int i = 0; i + 1 < n; i++) {
                if (nums[i + 1] - nums[i] <= maxDiff) {
                    ds.unionBySize(i, i + 1);
                }
            }

            vector<bool> ans;
            for (auto query : queries) {
                ans.push_back(ds.isConnected(query[0], query[1]));
            }

            return ans;
        }
    };