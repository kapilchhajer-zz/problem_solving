#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        
        vector<int> output;
               
        if(root == NULL)
                return output;
        
        stack<TreeNode *> stk;
        TreeNode *currentNode;
        stk.push(root);
        
        while(!stk.empty()){
            
            currentNode = stk.top();
            stk.pop();
            
            output.push_back(currentNode->val);
        
            if(currentNode->left == NULL && currentNode->right == NULL){
                continue;
            }
            
            if(currentNode->left != NULL)
                stk.push(currentNode->left); 
            
            
            if(currentNode->right != NULL)
                stk.push(currentNode->left);
            
        }
        
        return output;
    }
};

int main(){

	return 0;
}
