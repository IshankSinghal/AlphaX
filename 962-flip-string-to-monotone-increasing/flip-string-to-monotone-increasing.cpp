class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        stack<char> st;
        for(int i =0;i< s.size();i++){
            if(s[i]=='1') st.push(s[i]);
            if(s[i]=='0'){
                if(!st.empty() && st.top()=='1'){
                    st.pop();
                    ans++;
                }
            }
        }
        return ans;
    }
};