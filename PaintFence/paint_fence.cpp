class Solution {
public:
    /*
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
    	if (n==0 || k==0)
    		return 0;

    	if (k == 1 && n > 2)
    		return 0;

    	int f[n+2][k+2];
    	memset(f,0,sizeof(f));
    	for (int j = 1; j <= k; ++j)
	    	f[1][j] = f[2][j] = 1;

	    for (int i = 2; i <= n; ++i)
	    	for (int j = 1; j <= k; ++j)
	    		for (int p = 1; p <= k; ++p)
	    			if (p != j)
	    				f[i][j] += f[i-1][p] + f[i-2][p];
	    int res = 0;
	    for (int j = 1; j <= k; ++j)
	    	res += f[n][j];
	    return res;
    }
};
