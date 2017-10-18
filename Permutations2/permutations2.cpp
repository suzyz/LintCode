class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
    	vector<vector<int> > res;
       	int n = nums.size();
       	if (n == 0)
       	{
       		res.push_back(vector<int>());
       		return res;
       	}

       	sort(nums.begin(),nums.end());

       	int stack[n+1],top,it[n+1];
       	bool used[n+1];

       	for (int i = 0; i < n; ++i)
       	{
	       	top = 0;
	       	stack[top] = i;
	       	memset(used,0,sizeof(used));
	       	used[i] = true;
	       	it[top] = 0;

	       	while (top >= 0)
            {
	       		int cur = stack[top];
	       		if (top >= n-1)
	       		{
	       			vector<int> tmp(n,0);
	       			for (int j = 0; j < n; ++j)
	       				tmp[stack[j]] = nums[j];
	       			res.push_back(tmp);

	       			used[cur] = false;
	       			--top;
	       			continue;
	       		}
	       		
	       		if (it[top] > n-1)
	       		{
	       			used[cur] = false;
	       			--top;
	       			continue;
	       		}

	       		if (used[it[top]])
	       		{
	       			++it[top];
	       			continue;
	       		}

	       		if (top+1<n && nums[top+1] == nums[top] && it[top] <= cur)
	       		{
	       			it[top] = cur+1;
	       			continue;
	       		}

	       		used[it[top]] = true;
	       		stack[top+1] = it[top];
	       		it[top+1] = 0;

	       		++it[top];
	       		++top;
	       	}
       	}
       	return res;
    }
};
