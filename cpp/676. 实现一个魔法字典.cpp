/*


实现一个带有buildDict, 以及 search方法的魔法字典。

对于buildDict方法，你将被给定一串不重复的单词来构建一个字典。

对于search方法，你将被给定一个单词，并且判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。
示例 1:

Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-magic-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>


using namespace std;

// first method : 使用map存储word的通配符版本，进行查询
class MagicDictionary {
public:
    unordered_set<string> words;
    unordered_map<string, int> count;
    /** Initialize your data structure here. */
    MagicDictionary() {
        words.clear();
        count.clear();
    }

    vector<string> get_generalized_neighbors(string word){
        vector<string> ans;
        string generalized_neighbors = word;
        for (int i=0; i<generalized_neighbors.size(); i++){
            char letter = generalized_neighbors[i];
            generalized_neighbors[i] = '*';
            ans.push_back(generalized_neighbors);
        }
        return ans;
    }
    
    void buildDict(vector<string> dictionary) {
        // 
        for (int i=0; i<dictionary.size(); i++){
            words.emplace(dictionary[i]);
            vector<string> generalized_neighbors = get_generalized_neighbors(dictionary[i]);
            for (string generalized_neighbor : generalized_neighbors){
                // unordered_map默认空值为0
                count[generalized_neighbor] += 1;
            }
        }

    }
    
    bool search(string searchWord) {
        vector<string> generalized_neighbors = get_generalized_neighbors(searchWord);
        for (string generalized_neighbor : generalized_neighbors){
            if(count[generalized_neighbor] > 1){
                return true;
            }else if(count[generalized_neighbor] == 1 && !words.count(searchWord)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main(int argc, char const *argv[])
{
    vector<string> dic = {"hello","hallo","leetcode","judge"};
    MagicDictionary a;
    a.buildDict(dic);
    cout << a.search("hello") << endl;
    cout << a.search("hallo") << endl;
    cout << a.search("hell") << endl;
    cout << a.search("leetcodd") << endl;
    cout << a.search("judge") << endl;
    return 0;
}
// []
// [[], [["hello","hallo","leetcode","judge"]], ["hello"], ["hallo"], ["hell"], ["leetcodd"], ["judge"]]