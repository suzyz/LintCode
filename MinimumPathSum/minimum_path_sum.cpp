class Solution {
public:
    /*
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
    	int m = grid.size();
    	if (m==0)
    		return 0;

    	int n = grid[0].size();
    	if (n==0)
    		return 0;

    	int f[m][n];
    	for (int i = 0; i < m; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			f[i][j] = grid[i][j];
    			if (i == 0 && j == 0)
    				continue;
    			if (i == 0)
    				f[i][j] += f[i][j-1];
    			else
    			if (j == 0)
    				f[i][j] += f[i-1][j];
    			else
    				f[i][j] += min(f[i][j-1],f[i-1][j]);
    		}
    	}

    	return f[m-1][n-1];
    }
};
