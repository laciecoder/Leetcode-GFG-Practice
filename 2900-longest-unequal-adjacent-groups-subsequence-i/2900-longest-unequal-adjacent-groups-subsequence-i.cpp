class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> finalList;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            vector<string> cpy;
            int j = i;
            int prev = 0;
            int len = 0;
            while(j < n){
                if(cpy.empty()){
                    cpy.push_back(words[j]);
                    prev = groups[j];
                    len++;
                }
                else{
                    if(prev != groups[j]){
                        cpy.push_back(words[j]);
                        prev = groups[j];
                        len++;
                    }
                }
                j++;
            }
            if(len > maxLen){
                finalList = cpy;
                maxLen = len;
            }
        }
        return finalList;
    }
};