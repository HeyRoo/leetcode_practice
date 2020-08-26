/* 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
*/
#include<iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         set<vector<int>> res;
//         vector<int> tmp;
//     }

//     void dfs(vector<int> &nums, int idx, vector<int> &tmp, set<vector<int>> &res){
//         if(res.size()>1){
//             res.insert(tmp);
//         }

//         for(int j = idx; j < res.size(); j++){

//         }
//     }
// };

class Solution {
public:
    vector<int>t;
    void dfs(vector<vector<int>>&a,vector<int>&nums,int i)
    {
        if(i==nums.size())
        {
            if(t.size()>1)
            a.push_back(t);
            return;
        }
        if(!t.size()||nums[i]>=t[t.size()-1])
        {
            t.push_back(nums[i]);
            dfs(a,nums,i+1);
            t.pop_back();
        }
        if(!t.size()||nums[i]!=t[t.size()-1])
        //nums[i]是当前要考虑选不选的数字,t[t.size()-1]是已经选的数字的最后一个
        //比如已经选的是2345，nums[i]=5,上面已经考虑了选择了的即23455开头的所有序列
        //而这里不选nums[i]这个5直接递归到下一层选和将来回溯到2345的5不选变成234，再到这一层选
        //5的效果是一样的，所以进行这样的剪枝
            dfs(a,nums,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>a;
        dfs(a,nums,0);
        return a;
    }
};

template <class T>
void show(const T& x)
{
    cout << x << " ";
}

int main(int argc, char const *argv[])
{
    vector<int> input;
    int ia;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++ ){
        cin >> ia;
        input.push_back(ia);
    }

    Solution a;

    vector<vector<int>> res = a.findSubsequences(input);

    for(int i = 0; i < res.size(); i++){
        for_each(res[i].begin(),res[i].end(),show<int>);
        cout << " ;";
    }
    

    return 0;
}
