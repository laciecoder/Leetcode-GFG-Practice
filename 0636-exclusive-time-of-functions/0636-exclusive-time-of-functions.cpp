class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> stk;
        vector<int> ans(n);
        int prev = 0;
        for(string& op: logs){
            istringstream ss(op);
            string temp;
            int id = 0, time = 0;
            int cnt = 0;
            bool isStart = false;
            while(getline(ss, temp, ':')){
                if(cnt == 0)
                    id = stoi(temp);
                else if(cnt == 2)
                    time = stoi(temp);
                else
                    isStart = temp != "end";
                cnt++;
            }

            if(!stk.empty()){
                ans[stk.top()] += time - prev;
            }
            prev = time;
            if(isStart){
                stk.push(id);
            }
            else{
                ans[stk.top()]++;
                stk.pop();
                prev++;
            }
        }
        return ans;
    }
};