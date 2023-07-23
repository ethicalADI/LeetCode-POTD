// All Possible Full Binary Trees

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)  return {};
        TreeNode* head=new TreeNode(0);
        if(n==1)    return {head};

        vector<TreeNode*> ans;
        for(int i=1;i<n-1;i++){
            auto left = allPossibleFBT(i);
            auto right=allPossibleFBT(n-1-i);

            for(auto l:left){
                for(auto r:right){
                    TreeNode* temp=new TreeNode(0);
                    temp->left=l;
                    temp->right=r;
                    ans.push_back(temp);
                }
            }

        }
        return ans;
    }
};
