class Solution {
public:
    /*
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
    	int n = costs.size();
    	if (n==0)
    		return 0;
    	int m = costs[0].size();
    	int f[n+2][m+2], left[m+2], right[m+2];

    	for (int j = 0; j < m; ++j)
	   		f[0][j] = costs[0][j];

	   	for (int i = 1; i < n; ++i)
	   	{
	   		left[0] = INT_MAX;
	   		for (int j = 1; j < m; ++j)
	   			left[j] = min(f[i-1][j-1], left[j-1]);

	   		right[m-1] = INT_MAX;
	   		for (int j = m-2; j >= 0; --j)
	   			right[j] = min(f[i-1][j+1], right[j+1]);
	   		
	   		for (int j = 0; j < m; ++j)
	   			f[i][j] = costs[i][j] + min(left[j],right[j]);
	   	}

	   	int ans = INT_MAX;
	   	for (int j = 0; j < m; ++j)
	   		ans = min(ans,f[n-1][j]);
	   	return ans;
    }
};
