class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
    	int n = nums.size();
    	vector<int> ans(n,0);

    	priority_queue<int> smaller_half;
    	priority_queue<int,vector<int>,greater<int>> greater_half;

    	for (int i = 0; i < n; ++i)
    	{
    		if (smaller_half.size() == 0 || nums[i] < smaller_half.top())
    			smaller_half.push(nums[i]);
    		else
    			greater_half.push(nums[i]);

    		balance(smaller_half,greater_half);

    		if (smaller_half.size() >= greater_half.size())
    			ans[i] = smaller_half.top();
    		else
    			ans[i] = greater_half.top();
    	}
    	return ans;
    }

    void balance(priority_queue<int> &a,priority_queue<int,vector<int>,greater<int>> &b)
    {
    	if (a.size() > b.size() + 1)
    	{
    		b.push(a.top());
    		a.pop();
    	}
    	else
    	if (b.size() > a.size() + 1)
    	{
    		a.push(b.top());
    		b.pop();
    	}
    }
};
