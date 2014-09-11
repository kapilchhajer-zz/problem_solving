
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

// Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


struct TreeData{
     
        TreeNode *ptr;
        bool accessed;
        
        TreeData() : accessed(false), ptr(NULL) {}
        
 };


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        
        vector<int> output;
        
        
        if(root == NULL)
                return output;
        
        stack<TreeData *> stk;
        TreeData *node, *currentNode;
        TreeNode *temp;
        node = new TreeData();
        node->ptr = root;
        stk.push(node);
        
        while(!stk.empty()){
            
            currentNode = stk.top();
            temp = currentNode->ptr;
            stk.pop();
            
            if(currentNode->accessed){
                output.push_back(temp->val);
                continue;
            }
            
            
            
            if(temp->left == NULL && temp->right == NULL){
                output.push_back(temp->val);
                continue;
            }
            
            currentNode->accessed = true;
            stk.push(currentNode);
            
            if(temp->right != NULL){
                
                node = new TreeData();
                node->ptr = temp->right;
                stk.push(node);    
            }
            
            if(temp->left != NULL){
                
                node = new TreeData();
                node->ptr = temp->left;
                stk.push(node); 
            }
            
            
        
        }
        
        return output;
    }
};

