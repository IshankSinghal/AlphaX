class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = needle.length();

        if (size > haystack.length())
            return -1;
        if (size == haystack.length()) {
            if (needle == haystack)
                return 0;
            else
                return -1;
        }

        int i = 0;
        int j = size;

        while (i+j <= haystack.length()) {
            cout<<haystack.substr(i, j)<<endl;
            cout<<i<<endl<<j<<endl;
            if (haystack.substr(i, j) == needle) {
                return i;
            }
            i++;
        }
        return -1;
    }
};