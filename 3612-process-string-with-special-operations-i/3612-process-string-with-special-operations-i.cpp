class Solution {
public:
    string processStr(string s) {
        string ans;
        for(char ch: s){
            if(isalpha(ch)){
                ans.push_back(ch);
            }
            else if(ch == '#'){
                ans = ans + ans;
            }
            else if(ch == '*'){
                if(ans.size() > 0)
                    ans.pop_back();
            }
            else{
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};