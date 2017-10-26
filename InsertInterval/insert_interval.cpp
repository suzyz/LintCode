/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	int n = intervals.size();

    	if (n==0)
    	{
    		intervals.push_back(newInterval);
    		return intervals;
    	}

    	bool done = false;

    	vector<Interval>::iterator it = intervals.begin();
    	while (it!=intervals.end())
    	{
    		Interval cur = *it;
    		if (cur.begin > newInterval.end)
    		{
    			done = true;
    			intervals.insert(it,newInterval); //?
    			break;
    		}

    		if (cur.end < newInterval.start)
    		{
    			++it;
    			continue;
    		}
    		merge;
    	}
    }
};
