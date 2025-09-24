class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i = 0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        int n = nums2.size();
        vector<int> nge(n,-1);
        stack<int> st;
        st.push(0);
        
        for(int i =1; i<n; i++){
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                int topInd = st.top();
                st.pop();
                nge[topInd] = nums2[i];
            }
            st.push(i);
        }

        int newN = nums1.size();
        vector<int> result(newN,-1);
        for(int i =0; i< newN; i++){
            if(mp.find(nums1[i]) != mp.end()){
                int ind = mp[nums1[i]];
                result[i] = nge[ind];   // ✅ assign to i, not ind
            }
        }
        return result;
    }
};
