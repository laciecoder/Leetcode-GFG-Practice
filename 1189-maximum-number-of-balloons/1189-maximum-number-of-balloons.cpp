class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // balloon
        // b -> 1
        // a -> 1
        // l -> 2
        // o -> 2 
        // n -> 1
        vector<int> arr(26);
        for(char& ch: text){
            arr[ch - 'a']++;
        }
        return min({arr[1], arr[0], arr[11] / 2, arr[14] / 2, arr[13]});
    }
};