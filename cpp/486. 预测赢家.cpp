/* 
给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

 

示例 1：

输入：[1, 5, 2]
输出：False
解释：一开始，玩家1可以从1和2中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 False 。

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int length = nums.size();
        // 初始化nums长度大小的二维数组
        auto dp = vector<vector<int>> (length, vector<int>(length));
        // 对角线的值为nums原值
        for (int i = 0; i < length; i++) {
            dp[i][i] = nums[i];
        }
        /* 
        对于dp的状态转移方程，如下理解，如果一个数组，{a2，a3}增加一个元素a1，有两种可能{a1，a2，a3}，则玩家需判断取a1还是取a3；因为是最优方案，则判断取a1-{a2，a3}与取a3-{a1，a2}的最大值
         */
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][length - 1] >= 0;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
