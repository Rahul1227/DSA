class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        

        while(ss1 || ss2){
            string word1;
            string word2;
            
            if(ss1){
                getline(ss1,word1, '.');
            }

            if(ss2){
                getline(ss2,word2, '.');
            }
            int num1 = word1.size() > 0 ? stoi(word1) :0;
            int num2 = word2.size() > 0 ? stoi(word2) : 0;
            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
        }

        return 0;
    }
};