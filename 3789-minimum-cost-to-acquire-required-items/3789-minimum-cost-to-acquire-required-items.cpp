class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        return 1LL * min(need1, need2) * min(costBoth, cost1 + cost2) + 1LL * min(costBoth, cost1) * max(0, need1-need2) + 1LL * min(costBoth, cost2) * max(0, need2 - need1);
    }
};