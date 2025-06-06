class Solution {
public:
    string robotWithString(string s) {
        map<char, int> mp;
        string p, t;
        char start = 'a';
        for(char ch: s)
            mp[ch]++;
        for(char ch: s){
            t += ch;
            mp[ch]--;
            while(start < 'z' && mp[start] == 0){
                start++;
            }
            while(!t.empty() && t.back() <= start){
                p += t.back();
                t.pop_back();
            }
        }
        return p;
    }
};