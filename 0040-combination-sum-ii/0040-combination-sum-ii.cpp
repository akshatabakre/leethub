class Solution {
public:
    vector<vector<int>> list;
    void recfunc(vector<int>&v, int target,int ind,vector<int>& c){
        if(target==0){
            list.push_back(v);
            return;
        }
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i]==c[i-1]){
                continue;
            }
            if(c[i]>target){
                break;
            }
            v.push_back(c[i]);
            recfunc(v,target-c[i],i+1,c);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        recfunc(v,target,0,candidates);
        return list;
    }
};