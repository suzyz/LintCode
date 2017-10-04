class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
    	string res,tmp;
    	for (int i = 0; i < s.length(); ++i)
    		if (s[i] != ' ')
    		{
    			tmp.clear();
    			while (s[i] != ' ' && i < s.length())
    			{
    				tmp +=s[i];
    				++i;
    			}
    			res = tmp + " " + res;
    		}

    	while (res.length() > 0 && res[0] == ' ')
    		res.erase(res.begin());

    	while (res.length() > 0 && res[res.length()-1] == ' ')
    		res.erase(res.end()-1);

    	return res;
    }
};
