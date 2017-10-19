class Solution {
public:
    /*
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size();
        if (n==0)
        	return 0;
        int m = obstacleGrid[0].size();
        if (m==0 || obstacleGrid[0][0])
        	return 0;

        int f[m];
        memset(f,0,sizeof(f));
        f[0] = 1;
        for (int i = 0; i < n; ++i)
        	for (int j = 0; j < m; ++j)
        	{
        		if (obstacleGrid[i][j])
        			f[j] = 0;
        		else
        		if (j>0)
        			f[j] += f[j-1];
        	}
        return f[m-1];
    }
};
