class Solution {
public:
    /*
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
    	bool vis[k+2];
    	int now[k+2];

    	memset(vis,0,sizeof(vis));
    	vector<vector<int>> res;
    	select(1,k,n,now,vis,res);
    	return res;
    }

    void select(int cur,int k,int n,int *now,bool *vis,vector<vector<int>> &res)
    {
    	if (cur > k)
    	{
	    	vector<int> tmp(now+1,now+k+1);
	    	res.push_back(tmp);
    		
    		return;
    	}

    	int st = 1;
        if (cur>1)
            st = now[cur-1]+1;
    	for (int i = st; i <= n; ++i)
	    	if (!vis[i])
	    	{
	    		vis[i] = true;
	    		now[cur] = i;
	    		select(cur+1,k,n,now,vis,res);
	    		vis[i] = false;
	    	}
    }
};
