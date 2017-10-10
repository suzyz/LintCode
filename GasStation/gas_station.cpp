class Solution {
public:
    /*
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if (n==0)
        	return -1;

        int total = 0, sum = 0, st = 0;
        for (int i = 0; i < n; ++i)
        {
        	int cur = gas[i] - cost[i];
        	total += cur;
        	if (sum < 0)
        	{
        		sum = cur;
        		st = i;
        	}
        	else
        		sum += cur;
        }

        return total < 0 ? -1 : st;
    }
};