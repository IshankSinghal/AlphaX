//OPTIMAL SOLUTION (USING SET):-

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        if (n==0) return 0;
        int cnt = 0;
        int longest = 1;

        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it-1)==st.end()){
                cnt = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};