class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
    	vector<pair<int, double>> ans;
    	if (n==0)
    		return ans;

    	double f[n+2][6*n+2];
    	memset(f,0,sizeof(f));
    	for (int i = 1; i <= 6; ++i)
    		f[1][i] = 1.0/6;
    	
    	for (int i = 2; i <= n; ++i)
    		for (int j = i; j <= 6*i; ++j)
    		{
    			for (int k = 1; k <= 6; ++k)
    				f[i][j] += f[i-1][j-k];
    			
    			f[i][j] /= 6;
    		}
    		
    	for (int j = n; j <= 6*n; ++j)
    		ans.push_back(make_pair(j,f[n][j]));
    	return ans;
    }
};
