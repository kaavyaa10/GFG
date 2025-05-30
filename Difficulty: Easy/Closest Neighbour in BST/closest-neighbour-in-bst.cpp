/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int CNBST(Node* root, int &k){
        /*** 
        
        CNBST (Closest Neighbour in BST)
        
        Parameters
        
        1. root - A Node type pointer pointing to the root and its children nodes.
        
        2. k - Input number which would be compared with nodes data 
                and find the optimal solution.
        
        Return Conditions
        
        1. If null is encountered than function return -1(can be any negative no.)
            so that it would be less than every value of nodes in later comparisons.
        
        2. if a value greater than k is encountered that means we must go towards left
            child as it could be less than k and potential solution.
        
        3. return max of current node value and the potential solution coming from
            the right side of the node.
            
        **/
        
        if(!root){
            return -1;
        }
        if(root->data > k){
            return CNBST(root->left,k);
        }
        
        return max(root->data, CNBST(root->right,k));
    }
    int findMaxFork(Node* root, int k) {
        
        return CNBST(root,k);
    }
};