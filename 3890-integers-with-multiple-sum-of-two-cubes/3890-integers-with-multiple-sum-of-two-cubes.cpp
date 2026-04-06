class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int,int> f;
        for(int i=1;i*i*i<n;i++){
            for(int j=i;;j++){
                int sum =i*i*i + j*j*j;
                if(sum>n){
                    break;
                }
                f[sum]++;
            }
        }
        vector<int> ans;
        for(auto it:f){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};