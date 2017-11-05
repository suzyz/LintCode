class Solution {
public:
	const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
	int n,m;
	bool done;
    /*
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
    	n = board.size();
    	if (n==0 || word.length()==0)
    		return false;
    	m = board[0].size();
    	if (m==0)
    		return false;

    	done = false;
    	vector<vector<bool>> vis(n,vector<bool>(m,false));
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    			if (board[i][j] == word[0])
    			{
    				vis[i][j] = true;
    				dfs(1,i,j,board,vis,word);
    				vis[i][j] = false;
    				if (done)
    					return true;
    			}
    	}
    	return false;
    }

    void dfs(int cur,int x,int y,vector<vector<char>> &board,vector<vector<bool>> &vis,string &s)
    {
    	if (done)
    		return;
    	if (cur == s.length())
    	{
    		done = true;
    		return;
    	}

    	for (int i = 0; i < 4; ++i)
    	{
    		int tx = x + dir[i][0];
    		int ty = y + dir[i][1];
    		if (tx < 0 || ty < 0 || tx >= n || ty >= m)
    			continue;

    		if (vis[tx][ty] || board[tx][ty] != s[cur])
    			continue;

    		vis[tx][ty] = true;
    		dfs(cur+1,tx,ty,board,vis,s);
    		vis[tx][ty] = false;
    	}
    }
};
