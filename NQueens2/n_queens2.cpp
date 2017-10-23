class Solution {
public:
    /*
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
    	int res = 0;
    	bool col[n+2],diag1[2*n+2],diag2[2*n+2];
    	memset(col,0,sizeof(col));
    	memset(diag1,0,sizeof(diag1));
    	memset(diag2,0,sizeof(diag2));

    	for (int i = 0; i < n/2; ++i)
    	{
    		col[i] = diag1[i] = diag2[-i+n-1] = true;
    		dfs(1,n,col,diag1,diag2,res);
    		col[i] = diag1[i] = diag2[-i+n-1] = false;
    	}
    	res <<= 1;

    	if (n&1)
    	{
			col[n/2] = diag1[n/2] = diag2[-n/2+n-1] = true;
			dfs(1,n,col,diag1,diag2,res);
    	}

    	return res;
    }

    void dfs(int cur,int n,bool *col,bool *diag1,bool *diag2,int &res)
    {
    	if (cur==n)
    	{
    		++res;
    		return;
    	}

    	for (int i = 0; i < n; ++i)
    		if (!col[i] && !diag1[i+cur] && !diag2[cur-i+n-1])
    		{
    			col[i] = diag1[i+cur] = diag2[cur-i+n-1] = true;
    			dfs(cur+1,n,col,diag1,diag2,res);
    			col[i] = diag1[i+cur] = diag2[cur-i+n-1] = false;
    		}
    }
};
