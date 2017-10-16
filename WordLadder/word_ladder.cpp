class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
    	if (start == end)
    		return 1;

    	int n = start.length();
    	dict.insert(end);
		unordered_set<string> vis;

    	queue<string> qu;
    	qu.push(start);

    	int level = 1;
    	
    	while (!qu.empty())
    	{
    		++level;
    		int nums = qu.size();

    		while (nums--)
    		{
    			string x = qu.front(), y;
    			qu.pop();
    			for (int i = 0; i < n; ++i)
    			{
    				for (int j = 'a'; j <= 'z'; ++j)
    				{
    					y = x;
    					y[i] = j;

    					if (dict.count(y) && !vis.count(y))
    					{
    						if (y == end)
    							return level;

    						qu.push(y);
    						vis.insert(y);
    					}
    				}
    			}
    		}
    	}

    	return 0;
    }
};
