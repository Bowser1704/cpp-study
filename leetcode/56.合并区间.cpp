#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (39.33%)
 * Likes:    226
 * Dislikes: 0
 * Total Accepted:    40.8K
 * Total Submissions: 103.7K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals; 
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool { return a[0] < b[0]; });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // auto last = result.back();
            int back = result.size()-1;
            if (intervals[i][0] <= result[back][1]) result[back][1] = intervals[i][1] > result[back][1] ? intervals[i][1] : result[back][1];
            else result.push_back(intervals[i]);
        }
        return result;
    }
};
// @lc code=end
