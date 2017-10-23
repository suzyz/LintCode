class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
    	int n = A.length(), m = B.length();
    	int f[n+2][m+2];
    	memset(f,0,sizeof(f));

    	for (int i = 1; i <= n; ++i)
    		for (int j = 1; j <= m; ++j)
    		{
    			f[i][j] = max(f[i][j-1],f[i-1][j]);
    			if (A[i-1] == B[j-1])
    				f[i][j] = max(f[i][j],f[i-1][j-1]+1);
    		}

    	return f[n][m];
    }
};
