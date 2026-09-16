class Solution {
private:
    bool solve(int ind, vector<int>& arr, vector<int>& visited) {
        int n = arr.size();

        if(ind < 0 || ind >= n) return false;

        if(arr[ind] == 0) return true;

        if(visited[ind]) return false;

        visited[ind] = 1;

        bool left = solve(ind - arr[ind], arr, visited);
        if(left) return true;

        bool right = solve(ind + arr[ind], arr, visited);
        if(right) return true;

        return false;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<int> visited(n, 0);

        return solve(start, arr, visited);
    }
};