class Solution {
private:
    bool isPossible(int mid, vector<int> &piles, int h){
        int currHour = 0;
        for(int i =0; i< piles.size(); i++){
            currHour += ceil(1.000 * piles[i]/mid);
            if(currHour > h){
                return false;
            }
        }

        return currHour <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int ans = r;
        while(l<=r){
            int mid = l + ((r-l)/2);

            if(isPossible(mid, piles, h)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return l;

        
        
    }
};