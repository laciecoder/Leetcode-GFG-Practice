class Solution {
public:
    string countAndSay(int n) {
        string ans;
        ans = '1';
        while(--n){
            string copy;
            int i = 0;
            while(i < ans.size()){
                int cnt = 0;
                char prev = ans[i];
                while(i < ans.size() && ans[i] == prev){
                    i++;
                    cnt++;
                }
                copy += to_string(cnt);
                copy.push_back(prev);
            }
            ans = copy;
        }
        return ans;
    }
};