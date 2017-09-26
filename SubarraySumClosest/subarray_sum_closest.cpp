class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */

	bool cmp(pair<long long,int> &a,pair<long long,int> &b) {
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
       	int ans[2];
       	ans[0] = ans[1] = 0;

       	// if (n==0)
       	// 	return 0;
       	// if (n==1)
       	// 	return nums[0];

       	vector<pair<long long,int>> d;
       	long long sum = 0;
       	for (int i = 0; i < n; ++i)
       	{
       		sum += nums[i];
       		pair<long long,int> tmp(sum,i);
       		d.push_back(tmp);
       	}

       	sort(d.begin(),d.end(),cmp);

       	long long best = (long long)1 << 60;
       	for (int i = 1; i < n; ++i)
       	{
       		k = d[i].first - d[i-1].first;
       		if (d[i-1].second>d[i].second) {
       			k *= -1;
       		}
       		if (abs(k)<abs(best)) {
       			best = k;
       			ans[0] = d[i-1].second;
       		}
       	}
    }
};