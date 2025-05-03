class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        vector<int> mp1(7), mp2(7), mp3(7);
        int n = tops.size();
        for(int i = 0; i < n; i++){
            mp1[tops[i]]++;
            mp2[bottoms[i]]++;
            if(tops[i] == bottoms[i])
                mp3[tops[i]]++;
        }
        for(int i = 1; i < 7; i++){
            if(mp1[i] + mp2[i] - mp3[i] == n){
                ans = min({n - mp1[i], n - mp2[i], ans});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};