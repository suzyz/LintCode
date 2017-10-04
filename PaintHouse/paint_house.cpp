class Solution {
public:
    /*
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n==0)
        	return 0;

        int f[n][3];
        for (int i = 0; i < 3; ++i)
        	f[0][i] = costs[0][i];
        
        for (int i = 1; i < n; ++i)
        	for (int j = 0; j < 3; ++j)
        	{
        		f[i][j] = INT_MAX;
        		for (int k = 0; k < 3; ++k)
        			if (k != j)
        			{
        				int tmp = f[i-1][k] + costs[i][j];
        				f[i][j] = tmp<f[i][j] ? tmp:f[i][j];
        			}
        	}

        return min(min(f[n-1][0],f[n-1][1]),f[n-1][2]);
    }
};
