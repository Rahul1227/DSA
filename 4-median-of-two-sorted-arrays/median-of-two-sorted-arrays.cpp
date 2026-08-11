class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int totalLen = n1 + n2;

        int i =0;
        int j =0;

        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }else{
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1){
            temp.push_back(nums1[i]);
            i++;
        }

        while(j<n2){
            temp.push_back(nums2[j]);
            j++;
        }

        int half = totalLen/2;

        if(totalLen % 2 == 1){
            return temp[half];

        }else{
            double ans = (1.00 * temp[half-1] + temp[half])/2;
            return ans;
        }



    }
};