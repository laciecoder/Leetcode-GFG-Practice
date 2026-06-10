class Solution {
public:
    class SegmentTree{
        vector<int> tree;
        int n;
        void build(int node, int left, int right, vector<int>& arr){
            if(left == right){
                tree[node] = arr[left];
                return;
            }
            int mid = (left + (right - left) / 2);
            build(2 * node, left, mid, arr);
            build(2 * node + 1, mid + 1, right, arr);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
        int query(int node, int L, int R, int ql, int qr){
            if(ql > R || qr < L)
                return INT_MAX;
            if(ql <= L && R <= qr){
                return tree[node];
            }
            int mid = (L + (R - L) / 2);
            return min(query(2 * node, L, mid, ql, qr), query(2 * node + 1, mid + 1, R, ql, qr));
        }
        public: 
        SegmentTree(vector<int>& arr){
            n = arr.size();
            tree.resize(4 * n);
            build(1, 0, n - 1, arr);
        }
        int query(int l, int r){
            return query(1, 0, n - 1, l, r);
        }
    };
    long long maxTotalValue(vector<int>& nums, int k) {
        SegmentTree mini(nums);
        for(int& v: nums){
            v *= -1;
        }
        SegmentTree maxi(nums);
        int n = nums.size();
        priority_queue<tuple<int, int, int>> pq;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            pq.push({-maxi.query(i, n - 1) - mini.query(i, n - 1), i, n - 1});
        }

        while(k--){
            auto [v, l, r] = pq.top();
            pq.pop();
            if(r > l){
                pq.push({-maxi.query(l, r - 1) - mini.query(l, r - 1), l, r - 1});
            }
            ans += v;
        }

        return ans;
    }
};