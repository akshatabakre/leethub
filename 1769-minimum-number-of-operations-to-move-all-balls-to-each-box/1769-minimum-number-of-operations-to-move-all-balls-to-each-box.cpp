class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> balls;
        for(int i=0;i<boxes.length();i++){
            if(boxes[i]=='1'){
                balls.push_back(i);
            }
        }
        vector<int> answer(boxes.length());
        for(int i=0;i<answer.size();i++){
            int a = 0;
            for(int j=0;j<balls.size();j++){
                a += abs(i-balls[j]);
            }
            answer[i] = a;
        }
        return answer;
    }
};