class Solution {
public:
    /*
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        bool postive = false, negative = false;
        int product = 1, negative_product, postive_product , ans = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
        	product *= nums[i];

        	ans = product > ans ? product:ans;

        	if (product == 0)
        	{
        		product = 1;
        		postive = negative = false;
        	}
        	else
        	if (product < 0)
        	{
        		if (negative)
        		{
        			ans = max(ans,product/negative_product);
        			negative_product = max(negative_product,product);
        		}
        		else
        		{
        			negative_product = product;
        			negative = true;
        		}
        	}
        	else
        	{
        		if (postive)
        		{
        			ans = max(ans,product/postive_product);
        			postive_product = min(postive_product,product);
        		}
        		else
        		{
        			postive_product = product;
        			postive = true;
        		}
        	}
        }

        return ans;
    }
};
