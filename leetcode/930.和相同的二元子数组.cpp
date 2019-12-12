#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 *
 * https://leetcode-cn.com/problems/binary-subarrays-with-sum/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    1.6K
 * Total Submissions: 4.8K
 * Testcase Example:  '[1,0,1,0,1]\n2'
 *
 * 在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：A = [1,0,1,0,1], S = 2
 * 输出：4
 * 解释：
 * 如下面黑体所示，有 4 个满足题目要求的子数组：
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length <= 30000
 * 0 <= S <= A.length
 * A[i] 为 0 或 1
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int len = 0;
    int numSubarraysWithSum(vector<int>& A, int S) {
        int result = 0;
        len = A.size();
        if (S == 0) {
            int count = 0;
            for (int i = 0; i < len; i++) {
                if (A[i] == 0)
                    count++;
                else {
                    result += (count + 1) * count / 2;
                    count = 0;
                }
            }
            result += (count + 1) * count / 2;
        } else {
            int end0 = 0, end1 = 0, sum = 0;
            if (A[0] == S) {
                end0 = 0;
                for (int i = 1; i < len; i++) {
                    if (A[i] == 1) end1 = i;
                }
            } else {
                for (int i = 0; i < len; i++) {
                    if (sum == S && end0 > end1 && A[i] == 1) {
                        end1 = i;
                        break;
                    } else if (!end0) {
                        sum += A[i];
                        if (sum == S) {
                            end0 = i;
                        }
                    }
                }
            }
            if (sum == S) {
            result += end1 - end0;
            }else
            {
                return 0;
            }
            
            for (int i = 1; i < len; i++) {
                if (A[i - 1] == 1) {
                    if (end0 == len - 1) break;
                    end0 = end1;
                    if (end1 < len - 1)
                        end1 = find(A, end1 + 1);
                }
                result += end1 - end0 + 1;
            }
        }
        return result;
    }
    int find(vector<int>& A, int end1) {
        while (end1 < len && A[end1] != 1) {
            end1++;
        }
        return end1;
    }
};
// @lc code=end

//没有AC的暴力解法.
class ViloentSolution {
   public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int len = A.size(), result = 0;
        for (int i = 0; i < len; i++) {
            int sum = 0;
            for (int j = i; j < len; j++) {
                sum += A[j];
                if (sum == S) result++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> vec{0, 0, 0, 0, 0};
    solution.numSubarraysWithSum(vec, 0);
}