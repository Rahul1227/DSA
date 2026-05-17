class Solution {
private:
    void display(int i, int j, vector<char>&s){
        if(i>j) return;
        swap(s[i], s[j]);
        display(i+1, j-1, s);
        return;
    }
public:
    void reverseString(vector<char>& s) {
        int i =0;
        int j = s.size() -1;
        display(i,j, s);
        
    }
};