class Solution {
public:
    struct comp{
        bool operator ()(pair<char, int>& a, pair<char, int>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        for(int i = 0; i < s.size(); i++)
            if (s[i] != '*')
                pq.push({s[i], i});
            else {// did this since the index then needs to be sorted and processed 
                  // hint from solutions tab
                s[pq.top().second] = '*';
                pq.pop();
            }
        string ans;
        if(pq.size() == s.size())
            return s;
        for(auto ch: s)
            if(ch != '*')
                ans.push_back(ch);
        return ans;
    }
};