/*

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 可以考虑switch什么的，无序map的优点是查找快，应是hash的底层实现
        unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}
        };
        vector<string> res;
        string tmp;
        if(digits == ""){
            return res;
        }
        dfs(digits, table, res, tmp, 0);
        return res;
    }

    void dfs(string digits, unordered_map<char, string> table, vector<string> &res, string &tmp, int idx){
        //判断是否为答案
        if(tmp.size() == digits.size()){
            res.push_back(tmp);
            return ;
        }
        // 递归
        string key_stirng = table[digits[idx]];
        for(char w : key_stirng){
            // 
            tmp.push_back(w);
            dfs(digits, table, res, tmp, idx + 1);
            tmp.pop_back();
        }

        // 递归结束
        return ;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
