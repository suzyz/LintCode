class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */

  	static bool my_cmp(const pair<long long,int> &a,const pair<long long,int> &b) {
  		if (a.first < b.first)
  			return true;
  		if (a.first > b.first)
  			return false;
  		if (a.second < b.second)
  			return true;
  		return false;
  	}
    vector<int> subarraySumClosest(vector<int> &nums) {
       	int n = nums.size();
       	vector<int> ans;
        ans.push_back(0);
        ans.push_back(0);

       	if (n<2)
       		return ans;

       	vector<pair<long long,int>> d;
        pair<long long,int> tmp(0,-1);
        d.push_back(tmp);

       	long long sum = 0;
       	for (int i = 0; i < n; ++i)
       	{
       		sum += nums[i];
       		pair<long long,int> tmp(sum,i);
       		d.push_back(tmp);
       	}
        ++n;

       	sort(d.begin(),d.end(),my_cmp);

       	long long best = (long long)1 << 60;
       	for (int i = 1; i < n; ++i)
       	{
       		long long k = abs(d[i].first - d[i-1].first);

       		if (k<best) {
       			best = k;
       			ans[0] = min(d[i-1].second,d[i].second) + 1;
                ans[1] = max(d[i-1].second,d[i].second);
       		}
       	}

        if (ans[0] > ans[1]) {
            int tmp = ans[0]; ans[0] = ans[1]; ans[1] = tmp;
        }
        return ans;
    }
};