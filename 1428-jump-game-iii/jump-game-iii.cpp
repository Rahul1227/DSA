class Solution {
private:
    bool solve(int i, vector<int> &arr, vector<int> &visited){
        if(arr[i] == 0) return true;

        int left = i - arr[i];
        int right = i + arr[i];
        bool forward = false;
        bool backward = false;

        if(right < arr.size() && !visited[right]){
            visited[right] =1;
            forward = solve(right, arr, visited);

        }

        if(left >=0 && !visited[left]){
            visited[left] = 1;
            backward = solve(left, arr, visited);
        }


        return forward || backward;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);
        return solve(start, arr, visited);
        
    }
};