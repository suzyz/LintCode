class Solution {
public:
    /*
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
    	int n = A.size();
    	if (n==0)
    		return 0;
    	if (n==1)
    		return A[0];

    	long long last_robbed = A[0], last_not_robbed = 0, rob = 0, not_rob = 0;

    	for (int i = 1; i < n; ++i)
    	{
    		rob = max(rob,last_not_robbed + A[i]);
    		not_rob = max(not_rob,last_robbed);

    		last_not_robbed = not_rob;
    		last_robbed = rob;
    	}
    	return max(last_robbed,last_not_robbed);
    }
};
