class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int start = 0, end = min(workers.size(), tasks.size());
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        while(start < end){
            int mid = (start + end + 1) / 2, need = 0;
            multiset<int> set(workers.end() - mid, workers.end());
            for(int i = mid - 1; i >= 0; i--){
                auto it = prev(set.end());
                if(*it < tasks[i]){
                    it = set.lower_bound(tasks[i] - strength);
                    if(it == set.end() || ++need > pills)
                        break;
                }
                set.erase(it);
            }
            if(set.empty())
                start = mid;
            else
                end = mid - 1;
        }

        return start;
    }
};