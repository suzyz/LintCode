class Solution {
public:

    /*
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(),nums.end());
		
		vector<vector<int>> res;
		int n = nums.size();
		
		if (n == 0)
		{
			res.push_back(vector<int>());
			return res;
		}
		
		int top = 0, st[n+2], count[n+2];
		bool in_subset[n+1];
		
		top = 1;
		st[1] = 0;
		count[0] = 0;
		in_subset[0] = false;
		
		while (top)
		{
			int cur = st[top];
			if (cur == n)
			{
				--top;
				
				vector<int> tmp;
				for (int i = 1; i<= n; ++i)
					if (in_subset[i])
						tmp.push_back(nums[i-1]);
				
				res.push_back(tmp);
				continue;
			}
			
			if (count[top] == 2)
			{
				--top;
				continue;
			}
			
			if (count[top] == 0)
			{
				++count[top];
				in_subset[cur + 1] = false;
				st[++top] = cur + 1;
				count[top] = 0;
			}
			else
			if (count[top] == 1)
			{
				++count[top];
				
				if (cur>0 && !in_subset[cur] && nums[cur-1] == nums[cur]) /* The indices of vector nums !*/ 
					continue;
				
				in_subset[cur + 1] = true;
				st[++top] = cur + 1;
				count[top] = 0;
			}
		}
		
		return res;
	}
};
