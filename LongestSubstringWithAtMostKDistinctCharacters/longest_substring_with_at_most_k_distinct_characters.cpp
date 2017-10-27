#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    /*
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
    	if (s.length() == 0 || k <= 0)
    		return 0;

    	int l = 0, r = -1, ans = 0;
    	int total = 0, status[150];
    	memset(status,0,sizeof(status));

    	while (r<(int)s.length())
    	{
    		ans = max(ans,r-l+1);

    		if (r == s.length() - 1)
    			break;

    		++r;
    		if (status[s[r]] == 0)
    		{
    			++total;
    			while (total > k)
    			{
    				--status[s[l]];
    				if (status[s[l]] == 0)
    					--total;

    				++l;
    			}
    		}
    		
    		++status[s[r]];
    	}
    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string s1 = "onykowalsrolughyufhxigqkwalvfo";
	cout << s.lengthOfLongestSubstringKDistinct(s1,0) << endl;
	return 0;
}