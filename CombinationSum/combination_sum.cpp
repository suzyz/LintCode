class Solution {
public:
    /*
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());

        vector<int>::iterator pre = candidates.begin();
        for (vector<int>::iterator it = candidates.begin(); it != candidates.end(); )
        {
        	if (it != candidates.begin() && *it == *pre)
        		it = candidates.erase(it);
        	else
        	{
        		pre = it;
        		++it;
        	}
        }

        int count[n+1];
        memset(count,0,sizeof(count));
        vector<vector<int>> res;
        find_combination(0,n,candidates,0,target,count,res);

        return res;
    }

    void find_combination(int cur,int n,vector<int> &candidates, int sum,int target, int *count,vector<vector<int>> &res)
    {
    	if (sum == target)
    	{
    		vector<int> tmp;
    		for (int i = 0; i < cur; ++i)
    			for (int j = 0; j < count[i]; ++j)
    				tmp.push_back(candidates[i]);

    		res.push_back(tmp);
    		return;
    	}

 		if (cur >= n || sum > target)
    		return;

    	for (int i = 0; i <= (target-sum)/candidates[cur]; ++i)
    	{
    		count[cur] = i;
    		find_combination(cur+1,n,candidates,sum + i*candidates[cur],target,count,res);
    	}
    }
};
