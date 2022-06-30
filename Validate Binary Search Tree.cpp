/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/

// Solution 1: By Inorder Traversal we can get an array that is must be increasing order if the tree is valide BST . 

//Code:


class Solution {
public:
    
    void inorderTravers(TreeNode* root,vector<int>&vec){
        
        if(root->left!=NULL){
            inorderTravers(root->left,vec);
        }
        
        if(root!=NULL){
            vec.push_back(root->val);
        }
         if(root->right!=NULL){
            inorderTravers(root->right,vec);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<int>values;
        inorderTravers(root,values);
        int len = values.size();
        if(len<=1){
            return true;
        }
        
        for(int i=0;i<len-1;i++){
            if(values[i]>=values[i+1]){
                return false; 
            }
            //cout<<values[i]<<" ";
        }
        
        return true;
        
    }
};


// Solution 2: 

class Solution {
public:
    
    long long max_val = LLONG_MIN;
    bool is_BST = true;
    void inorderTravers(TreeNode* root,vector<int>&vec){
        
        if(is_BST == false){
            return;
        }
        if(root->left!=NULL){
            inorderTravers(root->left,vec);
        }
        
        if(root!=NULL){
            if(root->val>max_val){   //checking increasing order
                max_val = root->val;
            }else{
                is_BST = false;
            }
        }
         if(root->right!=NULL){
            inorderTravers(root->right,vec);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<int>values;
        inorderTravers(root,values);
        return is_BST;
        
    }
};
