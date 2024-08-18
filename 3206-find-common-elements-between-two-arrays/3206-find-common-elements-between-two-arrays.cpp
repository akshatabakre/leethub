class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int answer1 = 0, answer2 = 0;
        for(int i=0;i<nums1.size();i++){
            if(count(nums2.begin(),nums2.end(),nums1[i])!=0){
                answer1++;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(count(nums1.begin(),nums1.end(),nums2[i])!=0){
                answer2++;
            }
        }
        vector<int> answer(2);
        answer = {answer1,answer2};
        return answer;
    }
};