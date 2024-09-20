class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0, j=1,k=0;
vector<int> a(nums.size());
while(k<nums.size()){
if(nums[k]%2==0){
a[i]=nums[k++];
i+=2;
}else{
a[j]=nums [k++];
j+=2;
}
}
return a;
    }
};