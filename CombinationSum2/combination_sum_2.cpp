class Solution {
public:
    /*
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
    	vector<vector<int>> res;
    	int n = num.size();

    	sort(num.begin(), num.end());

    	while (n > 0 && num[n-1] > target)
    		--n;
    	
    	if (n==0)
    		return res;

    	bool used[n+2];
    	memset(used,0,sizeof(used));

    	dfs(0,n,num,target,used,res);
    	return res;
    }

    void dfs(int cur,int n,vector<int> &num,int target,bool *used,vector<vector<int>> &res)
    {
    	if (target == 0)
    	{
    		vector<int> tmp;
    		for (int i = 0; i < cur; ++i)
    			if (used[i])
    				tmp.push_back(num[i]);

    		res.push_back(tmp);
    		return;
    	}
    	if (cur == n || num[cur] > target)
    		return;

    	if (!(cur>0 && num[cur] == num[cur-1] && used[cur-1] == false))
    	{
	    	used[cur] = true;
	    	dfs(cur+1,n,num,target-num[cur],used,res);
	    	used[cur] = false;	
    	}

    	dfs(cur+1,n,num,target,used,res);
    }
};
