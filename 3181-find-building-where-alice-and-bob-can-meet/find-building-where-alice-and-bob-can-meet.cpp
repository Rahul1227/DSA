class Solution {
private:
    void buildTree(int i, int l, int r, vector<int>& heights,
                   vector<int>& seg) {
        if (l == r) {
            seg[i] = l;
            return;
        }

        int mid = l + ((r - l) / 2);
        buildTree(2 * i + 1, l, mid, heights, seg);
        buildTree(2 * i + 2, mid + 1, r, heights, seg);

        if (heights[seg[2 * i + 1]] > heights[seg[2 * i + 2]]) {
            seg[i] = seg[2 * i + 1];
        } else {
            seg[i] = seg[2 * i + 2];
        }
    }

    int getInd(int i, int l, int r, int start, int end, vector<int>& seg,
               vector<int>& heights) {
        if (r < start | l > end) {
            return -1;
        } else if (start <= l && r <= end) {
            return seg[i];
        } else {
            int mid = l + ((r - l) / 2);
            int leftInd = getInd(2 * i + 1, l, mid, start, end, seg, heights);
            int rightInd =
                getInd(2 * i + 2, mid + 1, r, start, end, seg, heights);

            if (leftInd == -1) {
                return rightInd;
            } else if (rightInd == -1) {
                return leftInd;
            } else if (heights[leftInd] > heights[rightInd]) {
                return leftInd;
            } else {
                return rightInd;
            }
        }
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> seg(4 * n);
        buildTree(0, 0, n - 1, heights, seg);
        int m = queries.size();
        vector<int> ans;

        for (auto query : queries) {
            int aPos = query[0];
            int bPos = query[1];
            if(aPos == bPos){
                ans.push_back(aPos);
                continue;
            }else if (bPos > aPos && heights[bPos] > heights[aPos]) {
                ans.push_back(bPos);
                continue;
            } else if (aPos > bPos && heights[aPos] > heights[bPos]) {
                ans.push_back(aPos);
                continue;
            } else {
                int l = max(query[0], query[1]);
                int r = n - 1;
                int tempAns = n;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    int currInd = getInd(0, 0, n - 1, l, mid, seg, heights);
                    if (heights[currInd] > heights[query[0]] &&
                        heights[currInd] > heights[query[1]]) {
                        tempAns = currInd;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }

                if (tempAns != n) {
                    ans.push_back(tempAns);

                } else {
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};