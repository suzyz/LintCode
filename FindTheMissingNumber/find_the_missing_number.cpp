class Solution {
public:
    /*
     * @param nums: An array of integers
     * @return: An integer
     */
    int findMissing(vector<int> nums) {
        int n = nums.size();
        bool flag = false;
        for (int i=0;i<n;i++)
            if (nums[i]==0)
            {
                nums[i]=n+1;
                flag=true;
            }

        if (!flag)
            return 0; 
            
        for (int i=0;i<n;i++) {
            int x = abs(nums[i]);
            if(x<n && nums[x]>0)
                nums[x] = -nums[x]; 
        }
            
        for (int i=1;i<n;i++)
            if (nums[i]>0)
                return i;
    
        return n;
    }
};