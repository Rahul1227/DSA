class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() > 0 && arr[i] < 0) {
                while (!st.empty() && st.top() > 0 && arr[i] < 0 &&
                       st.top() < abs(arr[i])) {
                    st.pop();
                }

                if (!st.empty() && st.top() > 0 && arr[i] < 0 &&
                    st.top() == abs(arr[i])) {
                    st.pop();
                    continue;
                }

                if (st.empty() || st.top() < 0) {
                    st.push(arr[i]);
                }

            } else {
                st.push(arr[i]);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};