class Solution {
public:
    /*
     * @param words: A list of words
     * @return: Return how many different rotate words
     */
    int countRotateWords(vector<string> words) {
    	int ans = 0;
    	for (vector<string>::iterator x = words.begin(); x != words.end(); )
    	{
    		bool flag = false;
    		for (vector<string>::iterator y = words.begin(); y != x; ++y)
    			if (is_rotate_words(*x,*y))
    			{
    				flag = true;
    				break;
    			}

    		if (flag)
    			x = words.erase(x);
    		else
    		{
    			++ans;
    			++x;
    		}
    	}
    	return ans;
    }

    bool is_rotate_words(string &a,string &b)
    {
    	if (a.length() != b.length())
    		return false;

    	int n = a.length();
    	for (int i = 0; i < n; ++i)
    	{
    		bool flag = true;
    		for (int j = 0; j < n; ++j)
    			if (a[j] != b[(i+j)%n])
    			{
    				flag = false;
    				break;
    			}
    		
    		if (flag)
    			return true;
    	}
    	return false;
    }
};
