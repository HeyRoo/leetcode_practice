/* 
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> num;
        for(int i=0;i<nums.size();i++){
            num[nums[i]]++;
        }
    
        vector<vector<int>> res={{}};
        vector<int> subset;
        for(auto item:num){
            int tmp=res.size();

            for(int m=0;m<tmp;m++){
                subset=res[m];
                for(int k=1;k<=item.second;k++){
                    subset.push_back(item.first);
                    res.push_back(subset);
                }
            }
        }
        
        return res;
        
    }
};

class Solution2 {
public:
    vector<int> subset;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int index){
        if(index>=nums.size()){
            return;
        }
        //再dfs地加子节点
        for(int j=index;j<nums.size();j++){//做的是子集，子集是组合，所以是从当前元素开始遍历
               if(j>index&&nums[j]==nums[j-1]) continue;//同层重复，跳过
               subset.push_back(nums[j]);
               ans.push_back(subset);
               dfs(nums, j+1);
               subset.pop_back();//撤销选择

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        ans.push_back({});
        return ans;
    }
};

template <class T>
void show(const T& x)
{
    cout << x << " ";
}

int main(int argc, char const *argv[])
{
    /* code */
    Solution2 a;
    vector<int> b = {1, 2, 2};
    vector<vector<int>> res = a.subsetsWithDup(b);
    sort(b.begin(), b.end());
    for(int i = 0; i < res.size(); i++){
        for_each(res[i].begin(),res[i].end(),show<int>);
        cout << " ;";
    }
    for_each(b.begin(), b.end(), show<int>);
    return 0;
}
