class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
    	int n = s.length();
    	if (n < 2)
    		return 0;

    	bool is_palindrome[n][n];
    	memset(is_palindrome,0,sizeof(is_palindrome));
    	for (int i = 0; i < n; ++i)
    		is_palindrome[i][i] = true;
    	for (int i = 0; i < n-1; ++i)
    		if (s[i] == s[i+1])
    			is_palindrome[i][i+1] = true;
    	
    	for (int i = 3; i <= n; ++i)
    		for (int j = 0; j <= n-i; ++j)
    			if (s[j] == s[j+i-1])
    				is_palindrome[j][j+i-1] |= is_palindrome[j+1][j+i-2];

    	int f[n+2];
    	f[0] = -1;
    	f[1] = 0;
    	for (int i = 1; i <= n; ++i)
    	{
    		f[i] = n-1;
    		for (int j = i-1; j >= 0; --j)
    			if (is_palindrome[j][i-1] && f[j]+1 < f[i])
    				f[i] = f[j]+1;
    	}
    	return f[n];
    }
};