typedef long long ll;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pScore(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int f = 2; f <= sqrt(num); f++) {
                if (num % f == 0) {
                    pScore[i]++;
                    while (num % f == 0)
                        num /= f;
                }
            }
            if (num >= 2)
                pScore[i]++;
        }

        vector<int> nextD(n, n), prevD(n, -1);
        stack<int> decStack;
        for (int i = 0; i < n; i++) {
            while (!decStack.empty() && pScore[decStack.top()] < pScore[i]) {
                int topIdx = decStack.top();
                decStack.pop();
                nextD[topIdx] = i;
            }
            if (!decStack.empty())
                prevD[i] = decStack.top();
            decStack.push(i);
        }

        vector<ll> subarrays(n);
        for (int i = 0; i < n; i++)
            subarrays[i] = (ll)(nextD[i] - i) * (i - prevD[i]);

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        ll score = 1;
        while (k > 0) {
            auto [num, idx] = pq.top();
            pq.pop();
            ll ops = min((ll)k, subarrays[idx]);
            score = (score * power(num, ops)) % MOD;
            k -= ops;
        }
        return score;
    }

private:
    ll power(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
};
