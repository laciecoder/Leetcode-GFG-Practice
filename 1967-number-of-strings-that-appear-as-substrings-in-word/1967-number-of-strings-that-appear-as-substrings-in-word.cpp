class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(auto pat: patterns){
            if(word.find(pat) != string::npos)
                count++;
        }
        return count;
    }
};