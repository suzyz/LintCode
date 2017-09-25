class Solution {
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> ans;
        int n = nums.size();
        if (n==0)
            return ans;
        
        long long pre,post[n];
        pre=post[n-1]=1;
        for (int i=n-2;i>=0;i--)
            post[i] = post[i+1]*nums[i+1];
        for (int i=0;i<n;i++) {
            ans.push_back(pre*post[i]);
            pre *= nums[i];
        }
        return ans;
    }
};
