class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        int maxEle = *max_element(arr.begin(), arr.end());
        int minEle = *min_element(arr.begin(), arr.end());
        int hashSize = maxEle - minEle + 1;
        vector<int> hashMap(hashSize, 0);
        unordered_map<int, int> visited;

        // filling the hashMap
        for(int i = 0; i<n ;i++){
            hashMap[arr[i] - minEle] ++;
        }
        
        for(int i =0; i< hashSize; i++){
            // int indEle = i + minEle;
            if(hashMap[i] > 0 && visited.find(hashMap[i]) != visited.end()) return false;
            visited[hashMap[i]] = 1;

        }
        return true;
    }
};