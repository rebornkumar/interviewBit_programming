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
           travel->left->val=X[cnt++];
           que.push(travel->left);
        }
        if(travel->right)
        {
           travel->right->val=X[cnt++];
           que.push(travel->right);
        }
    }
    return root;
}
 
void preOrder(TreeNode* root)
{
    if(root==NULL)return;
    cout<<root->val<<"   ";
    preOrder(root->left);
    preOrder(root->right);
    return;
}
TreeNode* preOrderSuccessor(TreeNode* X,int B)
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
            currNode=currNode->right;
        }
    }
    if(currNode->left)
    return currNode->left;
    else if(currNode->right)
    return currNode->right;
    else if(ancestor)
    return ancestor->right;
    else return NULL;
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
    TreeNode* rslt=preOrderSuccessor(root,B);
    if(rslt)
    cout<<rslt->val<<endl;
    else
    cout<<-1<<endl;
    //code ends here
    return 0;
}
