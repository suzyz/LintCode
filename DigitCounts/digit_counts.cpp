class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
    	if (k<0 || k>9)
    		return 0;

    	int res = (k==0);
    	for (int i = 1; i <= n; ++i)
    	{
    		int j = i;
    		while (j)
    		{
    			if (j%10 == k)
    				++res;
    			j/=10;
    		}
    	}
    	return res;
    }
};
