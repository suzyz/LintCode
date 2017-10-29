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
    	while (it != intervals.end())
    	{
    		Interval cur = *it;
    		if (cur.start > newInterval.end)
    		{
    			done = true;
    			intervals.insert(it,newInterval);
    			break;
    		}

    		if (cur.end < newInterval.start)
    		{
    			++it;
    			continue;
    		}

    		done = true;
            int st = min(cur.start,newInterval.start);
            int en = max(cur.end,newInterval.end);
            while (it != intervals.end() && overlapse(*it,newInterval))
            {
                en = max((*it).end,en);
                it = intervals.erase(it);
            }
            intervals.insert(it,Interval(st,en));
            break;
    	}
        if (!done)
            intervals.push_back(newInterval);

        return intervals;
    }

    bool overlapse(const Interval &a,const Interval &b)
    {
        if (a.end > b.start || b.end > a.start)
            return false;
        return true;
    }
};
