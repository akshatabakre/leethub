class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        bool equalsum = true;
        long long skillsum = skill[0] + skill[skill.size()-1];
        if(skill.size()>2){
            for(int i=1;i<skill.size()/2;i++){
            if(skill[i]+skill[skill.size()-i-1] != skillsum){
                equalsum = false;
                break;
            }
            }
        }
        long long res = -1;
        if(equalsum){
            res++;
            for(int i=0;i<skill.size()/2;i++){
                res += (skill[i]*skill[skill.size()-i-1]);
            }
        }
        return res;
    }
};