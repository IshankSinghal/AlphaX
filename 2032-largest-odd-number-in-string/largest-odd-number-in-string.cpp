class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.length()-1;i>=0;i--){
            int val = num[i]-'0';
            if(val%2 != 0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};