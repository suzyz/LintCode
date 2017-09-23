class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int n = A.length();
        int m = B.length();
        if(n==0 || m==0) return 0;
        
        int f[n][m],ans=0;
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (A[i]==B[j]) {
                    if (i==0 || j==0)
                        f[i][j] = 1;
                    else
                        f[i][j] = f[i-1][j-1]+1;
                        
                    if (f[i][j]>ans)
                        ans=f[i][j];
                }
                
        return ans;
    }
};
