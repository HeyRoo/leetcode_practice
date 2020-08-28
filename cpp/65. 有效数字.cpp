/*

验证给定的字符串是否可以解释为十进制数字。
*/ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> final_state = {0,0,0,1,0,1,1,0,1};
        // 
    vector<vector<int>> transfer_table = {
        { 0, 1, 6, 2,-1,-1},
        {-1,-1, 6, 2,-1,-1},
        {-1,-1, 3,-1,-1,-1},
        { 8,-1, 3,-1, 4,-1},
        {-1, 7, 5,-1,-1,-1},
        { 8,-1, 5,-1,-1,-1},
        { 8,-1, 6, 3, 4,-1},
        {-1,-1, 5,-1,-1,-1},
        { 8,-1,-1,-1,-1,-1}
    };

    int state = 0;

    int char_to_state(char a){
        switch (a)
        {
        case ' ':
            return 0;
        case '+':
        case '-':
            return 1;
        case '.':
            return 3;
        case 'e':
            return 4;   
        default:
            if(a >= '0' && a <='9'){
                return 2;
            }else{
                return 5;
            }
            break;
        }
    }

    bool isNumber(string s) {
        for(char i : s){
            state = transfer_table[state][char_to_state(i)];
            if(state < 0){
                return false;
            }
        }
        if(final_state[state]){
            return true;
        }else{
            return false;
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isNumber("0") << endl;
    return 0;
}
