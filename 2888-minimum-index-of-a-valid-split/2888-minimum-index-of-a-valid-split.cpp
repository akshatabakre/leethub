class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ind = -1, n = nums.size(), x = -1;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>n/2){
                x = nums[i];
            }
        }
        //watch the frequency of x, in the splitted arrays
        map<int,int> f;
        for(int i=0;i<n;i++){
            f[nums[i]]++;
            if(f[x]>(i+1)/2 && m[x]-f[x]>(n-i-1)/2){
                return i;
            }
        }
        return -1;
    }
};