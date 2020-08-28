/*
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

// 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> set;
    vector<string> res;

    void dfs(string from_site){
        string tmp;
        while(set.count(from_site) && set[from_site].size()){
            tmp = set[from_site].top();
            set[from_site].pop();
            // 此处，官方文档使用move()进行右值引用
            dfs(tmp);
        }
        // 使用emplace_back 可以减少开销
        res.push_back(from_site);
        return ;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string> ticket : tickets){
            set[ticket[0]].emplace(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<string>> a = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution b;
    b.findItinerary(a);
    for (int i=0; i<b.res.size(); i++){
        cout << b.res[i] << endl;
    }
    return 0;
}
