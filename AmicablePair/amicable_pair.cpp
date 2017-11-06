class Solution {
public:
    /*
     * @param k: An integer
     * @return: all amicable pairs
     */
    vector<vector<int>> amicablePair(int k) {
    	vector<vector<int>> res;

    	int sum[k+2];
    	memset(sum,-1,sizeof(sum));

    	for (int i = 2; i <= k; ++i)
    	{
    		if (sum[i] == -1)
	    		sum[i] = calc(i,k);
    		
    		if (sum[i] > k || sum[i] <= i)
    			continue;

    		int j = sum[i];
    		if (sum[j] == -1)
    			sum[j] = calc(j,k);

    		if (sum[j] == i)
    		{
    			int a[2];
    			a[0] = i;
    			a[1] = j;
    			res.push_back(vector<int>(a,a+2));
    		}
    	}
    	return res;
    }

    int calc(int cur,int k)
    {
    	int s = 1;
    	for (int j = 2; j < cur; ++j)
	    	if (cur%j == 0)
	    	{
	    		s += j;
	    		if (s>k)
	    			break;
	    	}
	    return s;
    }
};
