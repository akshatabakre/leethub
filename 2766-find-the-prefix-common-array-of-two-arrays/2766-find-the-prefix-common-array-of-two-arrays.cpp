class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ind(n);
        for(int i=0;i<n;i++){
            ind[A[i]-1] = i;
        }
        for(int i=0;i<n;i++){
            ind[B[i]-1] = max(ind[B[i]-1],i);
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[ind[i]]++;
        }
        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};