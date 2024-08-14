class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string x="",y="";
        int i;
        for(i=0;i<num1.length();i++){
            if(num1[i]!='+'){
                x+=num1[i];
            } else {
                break;
            }
        }
        i++;
        while(num1[i]!='i'){
            y+=num1[i];
            i++;
        }
        string a="",b="";
        i=0;
        while(num2[i]!='+'){
            a+=num2[i];
            i++;
        }
        i++;
        while(num2[i]!='i'){
            b+=num2[i];
            i++;
        }
        int r1 = stoi(x), i1 = stoi(y), r2 = stoi(a), i2 = stoi(b);
        string answer = "";
        string real = to_string((r1*r2)-(i1*i2));
        string im = to_string((r1*i2)+(r2*i1));
        answer+=real;
        answer+='+';
        answer+=im;
        answer+='i';
        return answer; 
    }
};