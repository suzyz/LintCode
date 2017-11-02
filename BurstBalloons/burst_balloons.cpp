class Solution {
public:
    /*
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
    	int n = nums.size();
    	int val[n+2];
    	val[0] = val[n+1] = 1;
    	for (int i = 1; i <= n; ++i)
    		val[i] = nums[i-1];

    	memset(f,0,sizeof(f));
    	for (int i = 1; i <= n; ++i)
    	{
    		for (int j = 1; j <= n-i+1; ++j)
    		{
    			f[j][i+j-1] = 0;
    			for (int k = j; k <= i+j-1; ++k)
    			{
    				
    			}
    		}
    	}
    }
};
