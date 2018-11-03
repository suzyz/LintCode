#include <iostream>
#include <vector>
#include <queue>

using namespace std;

 class mycmp
    {
        public:
          bool operator() (pair<int,int>& a, pair<int,int>& b) const
          {
            return a.first > b.first;
          }
    };
class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    // static bool mycmp(pair<int,int>& a, pair<int,int>& b) {
    //     return a.second > b.second;
    // }
   
    
    vector<int> getModifiedArray(int length, vector<vector<int> > &updates) {
        sort(updates.begin(), updates.end());
        vector<int> ans(length);
        
        int cur = 0, idx = 0, m = updates.size();
        priority_queue<pair<int,int>, vector<pair<int, int> >, mycmp>  pq;
        for (int i = 0; i < length; i++) {
            while (!pq.empty() && pq.top().first < i) {
                cur -= pq.top().second;
                // printf("%d pop:%d\n", i, pq.top().second);
                pq.pop();
            }
                
            while (idx < m && updates[idx][0] <= i) {
                pq.push(make_pair(updates[idx][1], updates[idx][2]));
                cur += updates[idx][2];
                // printf("%d push:%d\n", i, updates[idx][2]);
                ++idx;
            }
            
            ans[i] = cur;
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int> > data(3,vector<int>(3));
    int d[] = {1,3,2};
    data[0] = vector<int>(d, d+3);
    int d2[] = {2,4,3};
    data[1] = vector<int>(d2, d2+3);
    int d3[] = {0,2,-2};
    data[2] = vector<int>(d3, d3+3);
    s.getModifiedArray(5, data);
    return 0;
}