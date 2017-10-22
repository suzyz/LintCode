#include <cstdio>
#include <iostream>

#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

	struct Node
	{
		char c;
		bool is_word;
		int idx;
		Node *p[26];
		Node() { idx = 0; is_word = false; memset(p,0,sizeof(p)); }
		Node(char c1)
		{
			c = c1;
			idx = 0;
			is_word = false;
			memset(p,0,sizeof(p));
		}
	};
	class Trie
	{
	public:
		Node *root;
		Trie() { root = new Node; }

		void insert(string &w,int idx)
		{
			Node *cur = root;
			for (int i = 0; i < w.length(); ++i)
			{
				char c = w[i]-'a';
				if (!cur->p[c])
					cur->p[c] = new Node(c);
				cur = cur->p[c];
			}
			cur->is_word = true;
			cur->idx = idx;
		}
	};
	struct Status
	{
		int x,y;
		Node *ptr;
		vector<bool> used;

		Status(int x1,int y1,Node *p1,vector<bool> &u)
		{
			x = x1; y = y1; ptr = p1; used = u;
		}
	};

	void bfs(int x,int y,Node *p1,int n,int m,vector<vector<char> > &board,unordered_set<string> &res, vector<string> &words)
	{
		queue<Status> q;

		vector<bool> u(n*m,0);
		u[x*m+y] = true;
		Status init(x,y,p1,u);

		q.push(init);

		while (!q.empty())
		{
			Status cur = q.front();
			q.pop();

			if (cur.ptr->is_word)
				res.insert(words[cur.ptr->idx]);

			for (int i = 0; i < 4; ++i)
			{
				int tx = cur.x + dir[i][0];
				if (tx < 0 || tx >= n)
					continue;
				int ty = cur.y + dir[i][1];
				if (ty < 0 || ty >= m || cur.used[tx*m+ty])
					continue;

				if (!cur.ptr->p[board[tx][ty]-'a'])
					continue;

				Status next(tx,ty,cur.ptr->p[board[tx][ty]-'a'],cur.used);
				next.used[tx*m+ty] = true;
				q.push(next);
			}
		}
	}

	/*
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
    	int n = board.size();
    	if (n==0)
    		return vector<string>();

    	unordered_set<string> res;

    	Trie trie;
    	for (int i = 0; i < words.size(); ++i)
    		trie.insert(words[i],i);
    
    	int m = board[0].size();
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < m; ++j)
    			if (trie.root->p[board[i][j]-'a'])
    				bfs(i,j,trie.root->p[board[i][j]-'a'],n,m,board,res,words);

    	return vector<string>(res.begin(),res.end());
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	char b[3][5]={"abce","sfes","adee"};
	string w[] = {"abceseeefs","abceseedasfe"};
	vector<string> words(w,w+2);
	vector<vector<char> > board;
	board.push_back(vector<char>(b[0],b[0]+4));
	board.push_back(vector<char>(b[1],b[1]+4));
	board.push_back(vector<char>(b[2],b[2]+4));

	vector<string> res = s.wordSearchII(board,words);
	printf("res:\n");
	for (int i = 0; i < res.size(); ++i)
	{
		printf("%d:%s\n", i,res[i].c_str());
	}
	return 0;
}
