/* 

给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:

输入: "aacecaaa"
输出: "aaacecaaa"
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// use kmp algorithm , need to research this
class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        vector<int> next(n, -1);
        // next init
        for (int i = 1; i < n; i++)
        {
            int j = next[i - 1];
            while (j != -1 && s[j + 1] != s[i])
            {
                j = next[j];
            }
            if (s[j + 1] == s[i])
            {
                next[i] = j + 1;
            }
        }
        int prefix_end = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            while (prefix_end != -1 && s[prefix_end + 1] != s[i])
            {
                // move j index;
                prefix_end = next[prefix_end];
            }
            if (s[prefix_end + 1] == s[i])
            {
                prefix_end++;
            }
        }
        // reverse
        string ans = (prefix_end == n - 1 ? "" : s.substr(prefix_end + 1, n));
        reverse(ans.begin(), ans.end());

        return ans + s;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    a.shortestPalindrome("abcdabc");
    return 0;
}
