class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int> &nums) {
        int n = nums.size();
        int count1,count2,candidate1,candidate2;
        count1 = count2 = 0;
        for (int i = 0; i < n; ++i)
        {
        	if (count1 == 0)
        		candidate1 = nums[i];
        	else
        	if (count2 == 0)
        		candidate2 = nums[i];
        	
        	if (nums[i] == candidate1)
        		++count1;
        	else
        	if (nums[i] == candidate2)
        		++count2;
        	else
        	{
        		--count1;
        		--count2;
        	}
        }

        count1 = count2 = 0;
        for (int i = 0; i < n; ++i)
        {
        	if (nums[i] == candidate1)
        		++count1;
        	if (nums[i] == candidate2)
        		++count2;
        }

        return count1>count2 ? candidate1:candidate2;
    }
};
