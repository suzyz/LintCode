class Solution {
public:
    /*
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
    	vector<vector<int>> f = triangle;
    	int n = f.size();
    	if (n == 0)
    		return 0;

    	for (int i = 1; i < n; ++i)
    	{
    		f[i][0] += f[i-1][0];
    		f[i][i] += f[i-1][i-1];
    		for (int j = 1; j < i; ++j)
    			f[i][j] += min(f[i-1][j-1],f[i-1][j]);	
    	}

    	int ans = f[n-1][0];
    	for (int j = 1; j < n; ++j)
    		ans = f[n-1][j] < ans ? f[n-1][j] : ans;
    	return ans;
    }
};
