class Solution {
public:
    /*
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
    	if (m < 1 || n < 1)
    		return 0;

    	int f[m][n], ans = 0;
    	f[0][0] = 1;
    	for (int i = 0; i < m; ++i)
    		for (int j = 0; j < n; ++j)
    		{
    			if (i == 0 && j == 0)
    				continue;
    			if (i == 0)
    				f[i][j] = f[i][j-1];
    			else
    			if (j == 0)
    				f[i][j] = f[i-1][j];
    			else
    				f[i][j] = f[i][j-1] + f[i-1][j];
    		}
    	
    	return f[m-1][n-1];
    }
};
