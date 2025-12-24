class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size();
        int s = 0;
        for(int i:apple){
            s+=i;
        }
        sort(capacity.begin(), capacity.end());
        int t = 0;
        for(int i=m-1;i>=0;i--){
            t+=capacity[i];
            if(t>=s){
                return (m-i);
            }
        }
        return -1;
    }
};