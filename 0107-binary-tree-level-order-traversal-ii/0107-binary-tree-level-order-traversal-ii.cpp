void traverse(TreeNode* root,vector<vector<int>>&ans,int level){

    if(root==NULL)return;

    if(level==ans.size()){

        ans.push_back({}); 
    }

    ans[level].push_back(root->val);

    traverse(root->left,ans,level+1);

    traverse(root->right,ans,level+1);

   
 }

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>>ans;

        traverse(root,ans,0);

         reverse(ans.begin(),ans.end());
         
        return ans;
        
    }
};