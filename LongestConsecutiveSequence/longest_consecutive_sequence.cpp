class Solution {
public:
    /*
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s(num.begin(),num.end());
        int ans = 0;
        for (int i = 0; i < num.size(); ++i)
        {
        	if (!s.count(num[i]))
        		continue;
        	s.erase(num[i]);

        	int pre = num[i] - 1, next = num[i] + 1;
        	while (s.count(pre))
        		s.erase(pre--);
        	while (s.count(next))
        		s.erase(next++);

        	ans = max(ans,next - 1 - pre);
        }
        return ans;
    }
};
