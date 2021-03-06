class Solution {
public:
    /*
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
    	int n = word1.length();
    	int m = word2.length();
    	int f[n+2][m+2];

    	f[0][0] = 0;
    	for (int i = 1; i <= n; ++i)
    		f[i][0] = i;
    	for (int i = 1; i <= m; ++i)
    		f[0][i] = i;

    	for (int i = 1; i <= n; ++i)
    	{
    		for (int j = 1; j <= m; ++j)
    		{
    			f[i][j] = max(i,j);

    			if (word1[i-1] == word2[j-1])
    				f[i][j] = min(f[i][j],f[i-1][j-1]);
    			else
    				f[i][j] = min(f[i][j],f[i-1][j-1]+1);

    			f[i][j] = min(f[i][j],f[i-1][j]+1);
    			f[i][j] = min(f[i][j],f[i][j-1]+1);
    		}
    	}

    	return f[n][m];
    }
};
