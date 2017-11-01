class Solution {
public:
    /*
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
    	int n = A.size();
    	if (n==0)
    		return 0;
    	int ans = 1;

    	for (int diff = -1; diff <= 1; ++diff)
    	{
    		int i = diff == 1 ? 0:n-1;
    		while (i+diff < n && i+diff >= 0)
    		{
    			if (A[i] < A[i+diff])
    			{
    				int count = 1;
    				while (i+diff < n && i+diff >= 0 && A[i] < A[i+diff])
    				{
    					++count;
    					i += diff;
    				}
    				ans = max(ans,count);
    			}
    			else
    				i += diff;
    		}
    	}
    	return ans;
    }
};
