class Solution {
public:
    /*
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> pos;
        vector<int> ans;
        
        for (int i=0;i<numbers.size();i++) {
            map<int,int>::iterator q = pos.find(target-numbers[i]);
            
            if (q!=pos.end()) {
                ans.push_back(q->second+1);
                ans.push_back(i+1);
                return ans;
            }
            q = pos.find(numbers[i]);
            if (q==pos.end())
                pos[numbers[i]]=i;
        }
        return ans;
    }
};
