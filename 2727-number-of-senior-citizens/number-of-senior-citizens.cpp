class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i = 0; i<details.size(); i++){
            string str = details[i];
            string age = str.substr(11,2);
            if(stoi(age)>60) cnt++;
        }
        return cnt;
    }
};