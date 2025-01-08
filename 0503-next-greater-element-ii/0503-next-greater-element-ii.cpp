class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int maxind = -1, maxi = INT_MIN, n = nums.size();
        for(int i=0;i<n;i++){
            if(maxi<=nums[i]){
                maxind = i;
                maxi = nums[i];
            }
        }
        cout<<maxi<<" "<<maxind<<endl;
        vector<int> result(n);
        result[maxind] = -1;
        s.push(maxi);
        if(maxind>0){
            for(int i=maxind-1;i>=0;i--){
                while(!s.empty() && nums[i]>=s.top()){
                    s.pop();
                }
                if(s.empty()){
                    result[i] = -1;
                    s.push(nums[i]);
                }else{
                    result[i] = s.top();
                    s.push(nums[i]);
                }
                // cout<<result[i]<<" at "<<i<<endl;
            }
        }
        for(int i=n-1;i>=maxind+1;i--){
            while(!s.empty() && nums[i]>=s.top()){
                s.pop();
            }
            if(!s.empty()){
                result[i] = s.top();
                s.push(nums[i]);
            }else{
                result[i] = -1;
            }
        }
        return result;
    }
};