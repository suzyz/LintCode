class Solution {
public:
    /*
     * @param str: a string
     * @return: a compressed string
     */
    string compress(string &str) {
    	int n = str.length();
    	string res;
    	int i = 0;
    	while (i<n)
    	{
    		res += str[i];
    		if (i+1 < n && str[i+1] == str[i])
    		{
    			int count = 1;
    			++i;
    			while (i < n && str[i] == str[i-1])
    			{
    				++count;
    				++i;
    			}
    			res += to_string(count);
    		}
    		else
    		{
    			res += '1';
    			++i;
    		}
    	}

    	if (res.length() < n)
    		return res;
    	else
    		return str;
    }
};
