class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> lSum(n, 1), rSum(n, 1);
        int sum = 0;
        for(int i = 0; i < n - 1; i++)
            if(ratings[i] < ratings[i + 1])
                lSum[i + 1] = lSum[i] + 1;
        for(int i = n - 1; i > 0; i--)
            if(ratings[i] < ratings[i - 1])
                rSum[i - 1] = rSum[i] + 1;
        for(int i = 0; i < n; i++)  
            sum += max(lSum[i], rSum[i]);
        return sum;
    }
};