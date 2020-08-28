/* 
给定一个二叉树，在树的最后一行找到最左边的值。


 */

#include <iostream>
#include <queue>

using namespace std;

/**
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
// use dfs
// class Solution {
// public:
//     int degree = -1;
//     int ans;
//     void dfs(TreeNode* node, int depth){
//         if(node->left ==NULL && node->right == NULL && depth > degree){
//             degree = depth;
//             ans = node->val;
//             return ;
//         }
//         if(node->left != NULL){
//             dfs(node->left, depth + 1);
//         }
//         if(node->right != NULL){
//             dfs(node->right, depth + 1);
//         }
//         return ;
//     }

//     int findBottomLeftValue(TreeNode* root) {
//         dfs(root, 0);
//         return ans;
//     }
// };

// use bfs
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        TreeNode* ans;
        while(node_queue.size()){
            ans = node_queue.front();
            node_queue.pop();
            if(ans->right != NULL){
                node_queue.push(ans->right);
            }
            if(ans->left != NULL){
                node_queue.push(ans->left);
            }
        }
        return ans->val;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
