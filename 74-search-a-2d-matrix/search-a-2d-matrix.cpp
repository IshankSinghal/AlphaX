class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();
        int cnt = r*c;
        int low =0;
        int high = cnt-1;
        int mid = low+(high-low)/2;

        while(low<=high){
            int element = matrix[mid/c][mid%c];

            if(element == target) return true;
            else if(element<target) low=mid+1;
            else high=mid-1;
            mid = low+(high-low)/2;
        }
        return false;
    }
};