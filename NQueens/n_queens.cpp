class Solution {
public:
	struct Status {
		int row;
		int pos[20];
		int available_col, available_diag1, available_diag2;
	};
	
	/*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> res;
		
		queue<Status> q;
		
		Status init;
		init.row = 0;
		init.available_col = (1<<n)-1;
		init.available_diag1 = init.available_diag2 = (1<<(2*n-1))-1;
		q.push(init);
		
		while (!q.empty())
		{
			Status x = q.front();
			q.pop();
			int cur_row = x.row + 1;
			
			for (int i = 1; i <= n; ++i)
			{
				if (x.available_col & (1<<(i-1)))
					if (x.available_diag1 & (1<<(cur_row - i + n - 1)))
						if (x.available_diag2 & (1<<(cur_row + i - 2)))
						{
							Status y = x;
							y.row = x.row + 1;
							y.pos[y.row] = i;
							y.available_col -= (1<<(i-1));
							y.available_diag1 -= (1<<(cur_row - i + n - 1));
							y.available_diag2 -= (1<<(cur_row + i - 2));
							if (y.row == n)
								store_res(n,y,res);
							else
								q.push(y);	
						}
			}
		}
		
		return res;
	}
	
	void store_res(int n,Status &cur,vector<vector<string>> &res)
	{
		vector<string> s(n,string(n,'.'));
		
		for (int i = 1; i <= n; ++i)
			s[i-1][cur.pos[i]-1] = 'Q';
		
		res.push_back(s);
	}
};