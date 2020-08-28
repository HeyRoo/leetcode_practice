/*
给定一个方阵，其中每个单元(像素)非黑即白。设计一个算法，找出 4 条边皆为黑色像素的最大子方阵。

返回一个数组 [r, c, size] ，其中 r, c 分别代表子方阵左上角的行号和列号，size 是子方阵的边长。若有多个满足条件的子方阵，返回 r 最小的，若 r 相同，返回 c 最小的子方阵。若无满足条件的子方阵，返回空数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-black-square-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return {};
        }
        if(matrix.size() == 1){
            if(matrix[0][0] == 0){
                return {0, 0, 1};
            }else{
                return {};
            }
        }
        int size = matrix.size();
        vector<int> res(3, 0);
        // 正式开始
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>(2, 0)));
        for (int r = size - 1; r >= 0; r--){
            for (int c = size - 1; c >= 0; c--){
                // the block is white
                if(matrix[r][c] == 1){
                    dp[r][c][0] = dp[r][c][1] = 0;
                }else{
                    if(r == size - 1){
                        dp[r][c][0] = 1;
                    }else{
                        dp[r][c][0] = dp[r+1][c][0] +1;
                    }
                    if(c == size - 1){
                        dp[r][c][1] = 1;
                    }else{
                        dp[r][c][1] = dp[r][c+1][1] +1;
                    }
                }

                int len = min(dp[r][c][0], dp[r][c][1]);

                while(len >= res[2]){
                    if(dp[r + len - 1][c][1] >= len && dp[r][c + len - 1][0] >= len){
                        res = {r, c, len};
                        // 剪枝
                        break;
                    }
                    len--;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
