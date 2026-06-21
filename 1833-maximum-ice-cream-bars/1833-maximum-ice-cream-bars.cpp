class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        auto [mini, maxi] = minmax_element(costs.begin(), costs.end());
        int *arr = new int[(*maxi) - (*mini) + 1]();
        for(int cost: costs){
            arr[cost - (*mini)]++;
        }
        int cnt = 0;
        for(int i = 0; i <= (*maxi) - (*mini); i++){
            if(coins <= 0)
                break;
            while(*(arr + i) > 0 && ((*mini) + i) <= coins){
                cnt++;
                coins -= ((*mini) + i);
                *(arr + i) = *(arr + i) - 1;
            }
        }
        delete[] arr;
        return cnt;
    }
};