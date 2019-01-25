#include<bits/stdc++.h>
using namespace std;
 
struct TreeNode
{
    int val;
    TreeNode *left,*right;
    TreeNode(int data):val(data),left(NULL),right(NULL){}
};
 
TreeNode* createTree(int N)
{
    int cnt=1;
    TreeNode* root=new TreeNode(0);
    TreeNode* travel=root;
    queue<TreeNode*>que;
    que.push(root);
 
    while(cnt<N)
    {
            travel=que.front();
            que.pop();
            TreeNode* L_node=new TreeNode(0);
            TreeNode* R_node=new TreeNode(0);
            travel->left=L_node;
            travel->right=R_node;
            que.push(L_node);
            que.push(R_node);
            cnt+=2;
    }
    return root;
}
TreeNode* fillTree(TreeNode* root,vector<int>X)
{
    queue<TreeNode*>que;
    que.push(root);
    root->val=X[0];
    int cnt=1;
    TreeNode* travel;
    while(!que.empty())
    {
        travel=que.front();
        que.pop();
        if(travel->left)
        {
          if(X[cnt]!=INT_MAX)
          {
           travel->left->val=X[cnt++];
           que.push(travel->left);
          }
        //   else
        //   {
        //       travel->left=NULL;
        //   }
        }
        if(travel->right)
        {
           if(X[cnt]!=INT_MAX)
           {
           travel->right->val=X[cnt++];
           que.push(travel->right);
           }
        //   else
        //   {
        //       travel->right=NULL;
        //   }
        }
    }
    return root;
}
 
void postOrder(TreeNode* root)
{
    if(root==NULL)return;
 
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<"   ";
    return;
}
TreeNode* postOrderSuccessor(TreeNode* X,int B)
{
    TreeNode* ancestor=NULL;
    TreeNode* currNode=X;
    while(currNode)
    {
 
        if(currNode->val==B)
        {
            break;
        }
        else if(currNode->val>B)
        {
            //move left
             ancestor=currNode;
            currNode=currNode->left;
        }
        else
        {   
            ancestor=currNode;
            currNode=currNode->right;
        }
    }
   if(ancestor==NULL)return NULL;
   else if(ancestor->right==NULL||ancestor->right==currNode)
   return ancestor;
   else
   {
       ancestor=ancestor->right;
       while(ancestor->left!=NULL)
       ancestor=ancestor->left;
       return ancestor;
   }
 
}
 
int main()
{
    //code starts here
    int N;
    cin>>N;
    vector<int>X(N,-1);
    for(int i=0;i<N;i++)
    {
        cin>>X[i];
    }
    int B;
    cin>>B;
    TreeNode* A=createTree(N);
    TreeNode* root=fillTree(A,X);
    TreeNode* rslt=postOrderSuccessor(root,B);
    if(rslt)
    cout<<rslt->val<<endl;
    else
    cout<<-1<<endl;
    cout<<"LETS VERIFY OUTPUT HERE"<<endl;
    postOrder(root);
    //code ends here
    return 0;
}
