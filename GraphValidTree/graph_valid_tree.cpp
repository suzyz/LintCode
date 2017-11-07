class Solution {
public:
    /*
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
    	if (edges.size() != n-1)
    		return false;
    	
    	vector<int> fa(n,-1);

    	for (int i = 0; i < edges.size(); ++i)
    	{
    		int x = edges[i][0], y = edges[i][1];
    		int fx = get_fa(x,fa), fy = get_fa(y,fa);

    		if (fx == fy)
    			return false;
    		
    		union_xy(fx,fy,fa);
    	}

    	for (int i = 0; i < edges.size(); ++i)
    	{
    		int x = edges[i][0], y = edges[i][1];
    		int fx = get_fa(x,fa), fy = get_fa(y,fa);

    		if (fx != fy)
    			return false;
    	}

    	return true;
    }

    int get_fa(int cur,vector<int> &fa)
    {
    	int x = cur;
    	while (fa[x] >= 0)
    		x = fa[x];
    	
    	return x;
    }

    void union_xy(int x,int y,vector<int> &fa)
    {
    	if (fa[x] > fa[y])
    	{
    		fa[y] += fa[x];
    		fa[x] = y;
    	}
    	else
    	{
    		fa[x] += fa[y];
    		fa[y] = x;
    	}
    }

};
