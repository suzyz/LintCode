class Solution {
public:
    /*
     * @param stones: a list of stones' positions in sorted ascending order
     * @return: true if the frog is able to cross the river or false
     */
    bool canCross(vector<int> &stones) {
    	if (stones.size() == 1)
    		return true;
    	if (stones.size() > 1 && stones[1] != 1)
    		return false;

    	int n = stones.size();
    	unordered_map<int,int> positions;
    	for (int i = 0; i < stones.size(); ++i)
    		positions[stones[i]] = i;

    	bool f[n];
    	unordered_set<int> last_step[n];

    	memset(f,0,sizeof(f));
    	f[0] = f[1] = true;
    	last_step[1].insert(1);
    	for (int i = 1; i < n-1; ++i)
    		if (f[i])
    		{
    			for (unordered_set<int>::iterator j = last_step[i].begin(); j != last_step[i].end(); ++j)
    			{
    				int len = *j;
    				for (int k = -1; k <= 1; ++k)
    					if (len + k > 0)
    						if (positions.count(stones[i] + len + k))
    						{
    							int cur = positions[stones[i] + len + k];
    							if (cur == n-1)
    								return true;
    							f[cur] = true;
    							last_step[cur].insert(len+k);
    						}
    			}
    		}
    	return f[n-1];
    }
};
