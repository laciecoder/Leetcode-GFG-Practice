class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long ans = n * 2;
        unordered_map<int, vector<int>> mp;
        for(auto rs: reservedSeats){
            int row = rs[0], col = rs[1];
            if(!mp.count(row))
                mp[row] = vector<int>(11,1);
            mp[row][col] = -1;
        }
        for(auto [_, row]: mp){
            ans -= 2;
            int twofive = row[2] + row[3] + row[4] + row[5];
            int fourseven = row[4] + row[5] + row[6] + row[7];
            int sixnine = row[6] + row[7] + row[8] + row[9];
            if(twofive == 4 && sixnine == 4){
                ans += 2;
                continue;
            }
            ans = ans + ((twofive == 4) or (fourseven == 4) or (sixnine == 4));
        }
        return ans;
    }
};