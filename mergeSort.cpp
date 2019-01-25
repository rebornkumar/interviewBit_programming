#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>left,vector<int>right,vector<int>&A)
{
    int i=0,j=0,k=0;
    while(i<left.size()&&j<right.size())
    {
        if(left[i]<right[j])
        {
            A[k]=left[i];
            i++;
        }
        else
        {
            A[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<left.size())
    {
        A[k]=left[i];
        i++;k++;
    }
    while(j<right.size())
    {
        A[k]=right[j];
        j++;k++;
    }
}
void mergeSort(vector<int>&A)
{
    if(A.size()<2)
    return;
    int mid=A.size()/2;
    vector<int>left;
    vector<int>right;
    for(int i=0;i<mid;i++)
    {
        left.push_back(A[i]);
    }
    for(int i=mid;i<A.size();i++)
    {
        right.push_back(A[i]);
    }
    mergeSort(left);
    mergeSort(right);
    merge(left,right,A);
}
int main()
{
    //code
    int N;
    cin>>N;
    vector<int>A(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<N;i++)
    cout<<A[i]<<"  ";
    cout<<""<<endl;
    mergeSort(A);
    for(int i=0;i<N;i++)
    cout<<A[i]<<"  ";
    cout<<""<<endl;
    //code 
    return 0;
}
