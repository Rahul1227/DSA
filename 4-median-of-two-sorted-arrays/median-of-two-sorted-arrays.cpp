class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int len1 = nums1.size();
        int len2 = nums2.size();
        int totalLen = len1 + len2;

        int partionLen = (len1 + len2 + 1) /2;
        int l = 0;
        int r = len1;
        while(l <= r){
            int cut1 = l + ( r-l )/2;
            int cut2 = partionLen - cut1;

            int l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 -1]);
            int l2 = (cut2 == 0 ? INT_MIN : nums2[cut2-1]);

            int r1 = (cut1 == len1 ? INT_MAX : nums1[cut1]);
            int r2 = (cut2 == len2 ? INT_MAX : nums2[cut2]);

            if(l1 > r2){
                r = cut1 -1;
            }else if(l2 > r1){
                l = cut1 + 1;
            }else if(l1 <= r2 && l2 <= r1){
                if(totalLen%2 ==1 ){
                    return max(l1, l2);
                }else{
                    double ans = (max(l1, l2) + min(r1, r2)) /2.00;
                    return ans;
                }
            }
        }
        return -1.00;

        
    }
};