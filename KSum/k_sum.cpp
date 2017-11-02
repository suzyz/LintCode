class Solution {
public:
    /*
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
    int kSum(vector<int> &A, int k, int target) {
        int n = A.size();
        if (n < k || n == 0)
        	return 0;

        sort(A.begin(), A.end());
        while (n>0 && A[n-1] > target)
        	--n;

        int sum = 0, f[k+2][target+2];
        memset(f,0,sizeof(f));
        f[0][0] = 1;

        for (int i = 0; i < n; ++i)
        {
        	sum += A[i];
        	for (int j = min(i+1,k); j > 0; --j)
        		for (int p = min(target,sum); p >= A[i]; --p)
        			f[j][p] += f[j-1][p-A[i]];
        }
        
        return f[k][target];
    }
};
