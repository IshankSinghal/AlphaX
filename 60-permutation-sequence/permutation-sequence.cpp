class Solution {
public:
    string getPermutation(int n, int k) {
        // Initialize factorial to 1, which will be used to store (n-1)!
        int fact = 1;
        vector<int> num;

        // Populate the num vector with the numbers 1 to n-1
        // and calculate (n-1)! for later use in determining the k-th permutation.
        for(int i = 1; i < n; i++) {
            fact *= i;
            num.push_back(i);
        }
        // Push the nth number into the vector
        num.push_back(n);

        // Initialize the answer string to store the resulting permutation
        string ans = "";

        // Decrement k to make it zero-indexed
        k -= 1;

        // Build the permutation using the available numbers
        while(true) {
            // Append the k/fact th number to the answer string
            ans += to_string(num[k/fact]);

            // Remove the selected number from the list
            num.erase(num.begin() + (k/fact));

            // If no more numbers are left, break out of the loop
            if(num.size() == 0) break;

            // Update k and recalculate fact for the reduced problem size
            k %= fact;
            fact = fact / num.size();
        }

        // Return the final k-th permutation string
        return ans;
    }
};
