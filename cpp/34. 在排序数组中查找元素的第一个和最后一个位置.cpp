/* 
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lenth = nums.size();
        int left = 0, right = lenth-1;
        int start = 0, end = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                start = mid - 1;
                end = mid + 1;
                while (start >= 0 && nums[start] == target)
                {
                    start--;
                    /* code */
                }
                start++;
                while (end <= lenth -1 && nums[end] == target)
                {
                    end++;
                }
                end--;
                return {start, end};
            }else if (nums[mid] < target)
            {
                // left = mid + 1;
                left < mid + 1 ? left = mid + 1 : right + 1;
                /* code */
            }else
            {
                // right = mid - 1;
                right > mid - 1 ? right = mid - 1 : left - 1;
            }
        }
        return {-1, -1};
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = {1};
    Solution b;
    vector<int> ans = b.searchRange(a, 1);
    cout << ans[0] << " " << ans[1];
    return 0;
}
