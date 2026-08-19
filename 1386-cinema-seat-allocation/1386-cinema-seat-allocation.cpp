class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans = n * 2;
        unordered_map<int, int> mp;
        mp.reserve(reservedSeats.size() * 2);
        for(auto rs: reservedSeats){
            int row = rs[0], col = rs[1];
            
            mp[row] |= (1 << col);
        }
        int twofivemask = 0b0000111100;
        int foursevenmask = 0b0011110000;
        int sixninemask = 0b01111000000;
        for(auto [_, row]: mp){
            ans -= 2;
            
            if((row & twofivemask) == 0 && (row & sixninemask) == 0){
                ans += 2;
                continue;
            }
            ans = ans + (((row & twofivemask) == 0) or ((row & foursevenmask) == 0) or ((row & sixninemask) == 0));
        }
        return ans;
    }
};