class Solution {
public:
    int residuePrefixes(string s) {
        set<int> set;
        int ans = 0;
        int len = 0;
        for(char ch: s){
            set.insert(ch);
            len++;
            if(set.size() == (len % 3))
                ans++;
        }
        return ans;
    }
};