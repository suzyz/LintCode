class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        
        if (n==0)
            return ans;
        
        map<int,int> pos;
        
        if (nums[0]==0) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        
        int sum = 0;
        pos[0] = -1;
        for (int i=0;i<n;i++) {
            sum +=nums[i];

            map<int,int>::iterator it = pos.find(sum);

            if (it == pos.end()) {
                pos[sum] = i;
            }
            else {
                ans.push_back(it->second+1);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
