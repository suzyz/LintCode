class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        int n = A.size(), upper_bound = INT_MIN, lower_bound = INT_MAX;

        if (n < 2)
            return 0;
        if (target < 0)
            return INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            upper_bound = max(upper_bound,A[i]);
            lower_bound = min(lower_bound,A[i]);
        }

        upper_bound += target;
        lower_bound -= target;

        int f[n+2][upper_bound - lower_bound +2];
        for (int i = lower_bound; i <= upper_bound; ++i)
            f[0][i-lower_bound] = 0;
        
        for (int i = 1; i <= n; ++i)
        {
        	for (int j = lower_bound; j <= upper_bound; ++j)
        	{
        		f[i][j-lower_bound] = INT_MAX;

        		for (int k = max(lower_bound, j - target) ; k <= j + target && k <= upper_bound; ++k)
        			f[i][j-lower_bound] = min(f[i][j-lower_bound],f[i-1][k-lower_bound]);

        		if (f[i][j-lower_bound] != INT_MAX)
                    f[i][j-lower_bound] += abs(j - A[i-1]);
        	}
        }

        int ans = INT_MAX;
        for (int i = lower_bound; i <= upper_bound; ++i)
            ans = min(ans,f[n][i-lower_bound]);

        return ans;
    }
};
