class Solution {
private:
    bool solve(int ind, vector<int> &arr, vector<int> &visited){
        int n = arr.size();
        if(arr[ind] == 0) return true;

        int left = ind - arr[ind];
        int right = ind + arr[ind];

        bool forward = false;
        bool backward = false;
        if(left >=0 && !visited[left]){
            visited[left] = true;
            backward = solve(left, arr, visited);
        }

        if(right < n && !visited[right]){
            visited[right] = true;
            forward = solve(right, arr, visited);
        }

        return (backward || forward);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);
        visited[start] = 1;
        return solve(start, arr, visited);
    }
};