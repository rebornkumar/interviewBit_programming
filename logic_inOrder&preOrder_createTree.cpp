 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* create(vector<int>&X,vector<int>&Y)
{
    int indexX=0;
    int indexY=0;
    TreeNode* root=new TreeNode(X[0]);
    TreeNode* currNode=root;
 
    unordered_map<int,TreeNode*>hash;
    hash[X[0]]=root;
 
    int prevVisitedIndex;
    while(hash.size()<X.size())
    {
        while(X[indexX]!=Y[indexY])
        {
            indexX++;
            TreeNode* L_node=new TreeNode(X[indexX]);
          //  cout<<"X= "<<X[indexX]<<" Y= "<<Y[indexY]<<endl;
            currNode->left=L_node;
            currNode=L_node;
            hash[X[indexX]]=L_node;
        }
        while(hash.find(Y[indexY])!=hash.end())
        {
              prevVisitedIndex=indexY;
              indexY++;
        }
        TreeNode* R_node=new TreeNode(X[++indexX]);
        hash[Y[prevVisitedIndex]]->right=R_node;
      //  cout<<"Value in right node"<<R_node->val<<endl;
        hash[X[indexX]]=R_node;
      //  currNode=R_node;
     //   cout<<"parent of current node = "<<Y[prevVisitedIndex]<<"currNode->val = "<<currNode->val<<endl;
    }
    return root;
}
