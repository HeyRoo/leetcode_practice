/* 


给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<int>& cur, int idx,int n, int k, vector<vector<int>>& ans){
        if(cur.size() + (n-idx+1) < k){
            return ;
        }       
        if(cur.size()==k){
            ans.push_back(cur);
            return ;
        }

        cur.push_back(idx);
        dfs(cur, idx + 1, n, k, ans);
        cur.pop_back();
        dfs(cur, idx+1, n, k, ans);
        return ;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(cur, 1, n, k, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
