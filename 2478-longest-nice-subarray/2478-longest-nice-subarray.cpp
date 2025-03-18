class Solution {
public:
    bool check(vector<int>& nums,int len){
        vector<int> v(32,0);
        for(int i=0;i<len;i++){
            for(int j=0;j<32;j++){
                if(((1<<j) & nums[i])!=0){
                    v[j]++;
                }
            }
        }
        bool poss = true;
        for(int i=0;i<32;i++){
            if(v[i]>1){
                poss = false;
                break;
            }
        }
        if(poss)    return true;
        int i=0, j = len-1;
        while(j+1<nums.size()){
            //increment for nums[j+1]
            for(int k=0;k<32;k++){
                if(((1<<k)&nums[j+1])!=0){
                    v[k]++;
                }
            }
            //decrementing for nums[i];
            for(int k=0;k<32;k++){
                if(((1<<k)&nums[i])!=0){
                    v[k]--;
                }
            }
            //checking
            poss = true;
            for(int k=0;k<32;k++){
                if(v[k]>1){
                    poss = false;
                    break;
                }
            }
            if(poss)    return true;  

            i++;
            j++;  
        }
        return false;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int s = 1, e = nums.size(), ans = 1;
        while(s<=e){
            int len = s + (e-s)/2;
            if(check(nums,len)){
                cout<<len<<" true"<<endl;
                ans = len;
                s = len+1;
            }else{
                cout<<len<<" false\n";
                e = len-1;
            }
        }
        return ans;
    }
};