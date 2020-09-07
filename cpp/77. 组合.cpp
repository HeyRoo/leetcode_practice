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

    void dfs(vector<int>& arr, vector<int>& cur, int idx, int k, vector<vector<int>>& ans){
        
        if(arr.size()==k){
            ans.push_back(cur);
            return ;
        }
        if(!cur.size()||arr[idx]>=cur[cur.size()-1])
        {
            cur.push_back(arr[idx]);
            dfs(arr, cur, idx + 1, k, ans);
            cur.pop_back();
        }
        return ;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = i+1;
        }
        dfs(arr, cur, 0, k, ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
