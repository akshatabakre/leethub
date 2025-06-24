class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyInd;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key)    keyInd.push_back(i);
        }
        int m = keyInd.size();
        if(m==0){
            return {};
        }
        vector<int> kDisInd;
        for(int i=0;i<n;i++){
            bool kDis = false;
            for(int j=0;j<m;j++){
                if(abs(i-keyInd[j])<=k){
                    cout<<i<<" "<<j<<endl;
                    kDis = true;
                    break;
                }
            }
            if(kDis){
                kDisInd.push_back(i);
            }
        }
        return kDisInd;
    }
};