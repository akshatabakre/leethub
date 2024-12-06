class Solution {
public:
    vector<vector<int>> list;
    void recfunc(vector<int>& v,int target,int ind,vector<int>& c){
        if(target==0){
            list.push_back(v);
            cout<<"target met\n";
            return;
        }
        if(ind==c.size() || target<0){
            cout<<"returning w/o target\n";
            return;
        }
        //call for picking ind'th index
        v.push_back(c[ind]);
        recfunc(v,target-c[ind],ind,c);
        //call for not picking
        v.pop_back();
        recfunc(v,target,ind+1,c);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        recfunc(v,target,0,candidates);
        return list;
    }
};