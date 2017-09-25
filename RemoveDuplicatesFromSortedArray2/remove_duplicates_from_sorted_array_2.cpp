class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            vector<int>::iterator next = it+1;
            if (next == nums.end())
                break;
            if (*next == *it) {
                int count = 2;
                next = next+1;
                while (next != nums.end() && *next == *it) {
                    next = nums.erase(next);
                    n--;
                }
                ++it;
            }
            
            ++it;
        }
        return n;
    }
};
