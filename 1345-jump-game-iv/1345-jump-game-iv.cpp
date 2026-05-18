class Solution {
public:
    int minJumps(vector<int>& arr) {
        int PTR = INT_MIN;
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        q.push(PTR);
        visited.insert(0);
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        int time = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == PTR){
                if(!q.empty())
                    q.push(PTR);
                time++;
                continue;
            }
            if(front == n - 1)
                return time;
            if(front - 1 >= 0 && !visited.count(front - 1)){
                q.push(front - 1);
                visited.insert(front - 1);
            }
            if(front + 1 < n && !visited.count(front + 1)){
                q.push(front + 1);
                visited.insert(front + 1);
            }
            for(int next: mp[arr[front]]){
                if(!visited.count(next)){
                    visited.insert(next);
                    q.push(next);
                }
            }
            mp[arr[front]].clear();
        }

        return time;
    }
};