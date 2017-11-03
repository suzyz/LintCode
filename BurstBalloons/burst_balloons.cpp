class Solution {
public:
    /*
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
    	int n = nums.size();
    	int val[n+2], f[n+2][n+2];
    	val[0] = val[n+1] = 1;
    	for (int i = 1; i <= n; ++i)
    		val[i] = nums[i-1];

    	memset(f,0,sizeof(f));
    	for (int i = 1; i <= n; ++i)
    	{
    		for (int j = 1; j <= n-i+1; ++j)
    		{
    			f[j][j+i-1] = 0;
    			for (int k = j; k <= j+i-1; ++k)
    			{
    				int tmp = f[j][k-1] + f[k+1][j+i-1] + val[k] * val[j-1] * val[j+i];
                    f[j][j+i-1] = max(tmp,f[j][j+i-1]);
    			}
    		}
    	}
        return f[1][n];
    }
};
