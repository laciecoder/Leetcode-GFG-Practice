class Solution {
public:
    int minJumps(vector<int>& arr) {
        int PTR = INT_MIN;
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        q.push(PTR);
        visited[0] = true;
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
            if(front - 1 >= 0 && !visited[front - 1]){
                q.push(front - 1);
                visited[front - 1] = true;
            }
            if(front + 1 < n && !visited[front + 1]){
                q.push(front + 1);
                visited[front + 1] = true;
            }
            for(int next: mp[arr[front]]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
            mp[arr[front]].clear();
        }

        return time;
    }
};