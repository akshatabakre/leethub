class FindSumPairs {
public:
    map<int,int> f1;
    vector<int> vec;
    map<int,int> f2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i:nums1){
            f1[i]++;
        }
        this->vec = nums2;
        for(int i:vec){
            f2[i]++;
        }
    }
    
    void add(int index, int val) {
        f2[vec[index]]--;
        vec[index] += val;
        f2[vec[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto it:f1){
            int num = it.first;
            int f = it.second;
            ans += f*f2[tot-num];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */