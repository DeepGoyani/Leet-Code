class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root) return 0;

      queue<TreeNode*> q;
      q.push(root);
      int depth=0;

      while (!q.empty()){
        int size=q.size();
        depth++;
      for(int i=0;i<size;i++){
        TreeNode* current=q.front();
        q.pop();

        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
      }
      }
      return depth;

    }
};
