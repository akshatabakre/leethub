class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        #define int long long
        int n = nums.size();
        vector<int> res;
        stack<int> s;
        s.push(nums[0]);
        for(int i=1;i<n;i++){
            int x = nums[i];
            while(!s.empty() && s.top()==x){
                x+=s.top();
                s.pop();
            }
            s.push(x);
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        #undef int
    }
};