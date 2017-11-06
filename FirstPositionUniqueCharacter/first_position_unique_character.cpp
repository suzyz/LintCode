class Solution {
public:
    /*
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        int n = s.length();
        int num[300];
        memset(num,0,sizeof(num));
        for (int i = 0; i < n; ++i)
        	++num[s[i]];
        for (int i = 0; i < n; ++i)
        	if (num[s[i]] == 1)
        		return i;
        return -1;
    }
};
