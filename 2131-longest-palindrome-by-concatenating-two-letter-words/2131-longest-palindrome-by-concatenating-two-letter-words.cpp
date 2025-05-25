class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for(string& w: words)
            mp[w]++;
        int len = 0, same = 0;
        for(auto& [w, cnt]: mp){
            string rev = string(w.rbegin(), w.rend());
            if(w == rev){
                len += (cnt / 2) * 4; // to handle aa case and cnt is 1
                if(cnt & 1)
                    same = 1;
            }
            else if (w < rev && mp.count(rev)){
                len += min(cnt, mp[rev]) * 4;
            }
        }
        return len + same * 2; 
    }
};