class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string s, string p) {
    	int n = s.length(), m = p.length();
    	bool f[n+2][m+2];
    	memset(f,0,sizeof(f));
    	f[0][0] = true;
    	// for (int j = 1; j <= m && p[j-1] == '*'; ++j)
    	// 	f[0][j] = true;
    	for (int j = 2; j <= m; j+=2)
    		if (f[0][j-2] && p[j-1] == '*')
    			f[0][j] = true;
    		else
    			break;

    	for (int i = 1; i <= n; ++i)
	    	for (int j = 1; j <= m; ++j)
	    	{
	    		if (s[i-1] == p[j-1] || p[j-1] == '.')
	    			f[i][j] |= f[i-1][j-1];
	    		else
	    		if (p[j-1] == '*' && j>1)
	    		{
	    			f[i][j] |= f[i][j-2];
	    			if (f[i][j])
	    				continue;

	    			for (int k = i; k > 0 && (p[j-2] == '.' || s[k-1] == p[j-2]); ++k)
	    				if (f[k-1][j-2])
	    				{
	    					f[i][j] = true;
	    					break;
	    				}
	    		}
	    	}

	    return f[n][m];
    }
};
