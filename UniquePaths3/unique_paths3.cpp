class Solution {
public:
    /*
     * @param : an array of arrays
     * @return: the sum of all unique weighted paths
     */
    int uniqueWeightedPaths(vector<vector<int>>& grid) {
    	int n = grid.size();
    	if (n==0)
    		return 0;
    	int m = grid[0].size();
    	if (m==0)
    		return 0;

    	unordered_set<int> f[n+2][m+2];
    	int tmp = grid[0][0];
    	f[0][0].insert(tmp);
    	for (int i = 1; i < n; ++i)
    	{
    		tmp += grid[i][0];
    		f[i][0].insert(tmp);
    	}

    	tmp = grid[0][0];
    	for (int j = 1; j < m; ++j)
    	{
    		tmp += grid[0][j];
    		f[0][j].insert(tmp);
    	}
    	
    	for (int i = 1; i < n; ++i)
    	{
    		for (int j = 1; j < m; ++j)
    		{
    			for (unordered_set<int>::iterator it = f[i-1][j].begin(); it != f[i-1][j].end(); ++it)
    				f[i][j].insert(*it + grid[i][j]);

    			for (unordered_set<int>::iterator it = f[i][j-1].begin(); it != f[i][j-1].end(); ++it)
    				f[i][j].insert(*it + grid[i][j]);
    		}
    	}

    	int sum = 0;
    	for (unordered_set<int>::iterator it = f[n-1][m-1].begin(); it != f[n-1][m-1].end(); ++it)
    		sum += *it;

    	return sum;
    }
};
