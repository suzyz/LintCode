class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        int n = A.size(), maxv = INT_MIN, minv = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            maxv = max(maxv,A[i]);
        	minv = min(minv,A[i]);
        }
      	for (int i = 0; i < n; ++i)
      	{
      		// A[i] -= minv;
      		
      	}
        int f[n+2][maxv+target+2];

        for (int i = 1; i <= n; ++i)
        {
        	for (int j = ; j <= ; ++j)
        	{
        		f[i][j] = INT_MAX;
        		for (int k = ; k < ; ++k)
        		{
        			f[i][j] = min(f[i][j],f[i-1][k] + abs(j-A[i-1]));
        		}
        	}
        }
    }
};
