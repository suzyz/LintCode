class Solution {
public:
    /*
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
    	int n = str.length();
    	if (n == 0 || offset%n == 0)
    		return;

    	offset %= n;
    	for (int i = 0; i < offset; ++i)
    	{
    		char c = str[n-1];
    		for (int j = n-1; j > 0; --j)
    			str[j] = str[j-1];
    		str[0] = c;
    	}
    }
};
