class Solution {
public:
    /*
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> nums, int k) {
    	priority_queue<int> heap(nums.begin(), nums.end());
    	vector<int> res;
    	for (int i = 0; i < k; ++i)
    	{
    		res.push_back(heap.top());
    		heap.pop();
    	}
    	return res;
    }
};
