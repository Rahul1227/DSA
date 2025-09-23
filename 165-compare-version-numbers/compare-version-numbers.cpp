class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> arr1;
        vector<int> arr2;
        int num1=0;
        int num2=0;
        
        for(auto c : version1){
            if(c == '.'){
                arr1.push_back(num1);
                num1 = 0;

            }else{
                num1 = num1 * 10 + (c - '0');

            }
        }
        arr1.push_back(num1);
        
        for(auto c : version2){
            if(c == '.'){
                arr2.push_back(num2);
                num2 = 0;

            }else{
                num2 = num2 * 10 + (c - '0');

            }
        }
        arr2.push_back(num2);

        int result = 0;

        int len1 = arr1.size();
        int len2 = arr2.size();

        int len = min(len1, len2);

        for(int i =0; i<len; i++){
            if(arr1[i] == arr2[i]) continue;
            if(arr1[i] < arr2[i]){
                result =-1;
                break;

            } 
            if (arr1[i] > arr2[i]){
                 result = 1;

                 break;

            }
        }

        if(result == 0 && len1 > len2){
            int sum = accumulate(arr1.begin()+len2, arr1.end(),0);
            if(sum > 0)  result = 1;
            cout<<sum<<" ";
        }

        if(result == 0 && len2 > len1){
            int sum = accumulate(arr2.begin()+ len1, arr2.end(),0);
            if(sum > 0) result = -1;
            // cout<<sum<<" ";
        }


        return result;

        
    }
};