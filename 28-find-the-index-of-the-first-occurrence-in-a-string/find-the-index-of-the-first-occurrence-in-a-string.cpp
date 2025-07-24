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

        for (int i = 0; i <= haystack.length() - size; i++) {
            if (haystack.substr(i, size) == needle)
                return i;
        }
        return -1;
    }
};