/*

Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
Example 3:

Input: intervals = [[0,10],[5,12]]
Output: 2
Example 4:

Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2
Example 5:

Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= intervals[i][0] < intervals[i][1] <= 10^5
All the intervals are unique.

*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        int count = size;
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b) {
           if (a[0] < b[0]) {
               return true;
           } else if (a[0] > b[0]) {
               return false;
           } else {
               return a[1] > b[1];
           }
        });
        
        for(int i = 0;i<size;++i) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            for(int j = 0;j < i;++j) {
                if (intervals[j][0] <= l && intervals[j][1] >= r) {
                    --count;
                    break;
                }
            }
        }
        return count;
    }
};