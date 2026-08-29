class Solution {
private:
    bool canPlace(int num, vector<vector<int>> &groups, unordered_set<int> &taken, int groupSize){
        for(int i=0; i<groups.size(); i++){
            if(taken.count(i)) continue;
            if(groups[i].size() == 0 || num - groups[i].back() == 1){
                groups[i].push_back(num);
                if(groups[i].size() == groupSize){
                    taken.insert(i);
                }
                return true;
            }
        }
        return false;
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        int groupCount = n / groupSize;
        vector<vector<int>> groups(groupCount);
        unordered_set<int> taken;

        sort(hand.begin(), hand.end());

        for(auto num: hand){
            if(!canPlace(num, groups, taken, groupSize)){
                return false;
            }
        }
        // for(auto group: groups){
        //     for(auto num: group){
        //         cout<<num<<" ";
        //     }
        //     cout<<endl;

        // }
        return true;
        
    }
};