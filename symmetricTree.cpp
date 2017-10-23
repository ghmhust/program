#include <iostream>
#include <vector>
#include <string>
/*
 * leetcode 10.23
 * 看二叉树是不是镜像对称的
 * */
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void getmid1(TreeNode* root,vector<string>& inorder1){
        if(root) getmid1(root->left,inorder1);
        if(root) getmid1(root->right,inorder1);
        if(root == NULL) inorder1.push_back("NULL");
        else inorder1.push_back(to_string(root->val));
    }
    void getmid2(TreeNode* root,vector<string>& inorder2){
        if(root) getmid2(root->right,inorder2);
        if(root) getmid2(root->left,inorder2);
        if(root == NULL) inorder2.push_back("NULL");
        else inorder2.push_back(to_string(root->val));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        vector<string> inorder1,inorder2;
        getmid1(root,inorder1);
        getmid2(root,inorder2);
        int len = inorder1.size();
        for(int i = 0;i<len;++i){
            if(inorder1[i] != inorder2[i]) return false;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}