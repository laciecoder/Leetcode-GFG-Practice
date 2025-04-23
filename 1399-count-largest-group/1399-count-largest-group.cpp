class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxi = 0, count = 0;
        for(int i = 1; i <= n; i++)
            maxi = max(maxi, ++mp[getSum(i)]);
        
        for(auto [_, v]: mp)
            if(v == maxi)
                count++;
        
        return count;
    }
};