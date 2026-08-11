class Solution {
private:
    double solve(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        int totalLen = n1+n2;
        int parLen = (n1 + n2 + 1)/2;
        int l = 0;
        int r = n1;

        while(l <= r){
            int cut1 = l + (r-l)/2;
            int cut2 = parLen - cut1;

            int l1 = (cut1 == 0 ? INT_MIN :nums1[cut1-1]);
            int l2 = (cut2 == 0 ? INT_MIN: nums2[cut2-1]);

            int r1 = (cut1 == n1 ? INT_MAX : nums1[cut1]);
            int r2 = (cut2 == n2 ? INT_MAX : nums2[cut2]); 

            if(l2 > r1){
                l = cut1 + 1;
            }else if(l1 > r2){
                r = cut1 -1;
            }else if(l1 <= r2 && l2 <= r1){
                if(totalLen % 2 == 1){
                    return max(l1, l2);
                }else{
                    double ans = (1.000 * max(l1, l2) + min(r1, r2)) / 2;
                    return ans;
                }
            }
        }

        return 0.00;


    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        double result = 0.000;
        if(n1 < n2){
            result = solve(nums1, nums2);
        }else{
            result = solve(nums2, nums1);
        }

        return result;       
    }
};