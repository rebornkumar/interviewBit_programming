class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        int N=nums.size();
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=nums[i];
 
        vector<vector<int>>A(N,vector<int>(N,0));
        for(int i=0;i<N;i++)
        {
            A[i][i]=nums[i];
            if(i+1<N)
            {
                A[i][i+1]=max(nums[i],nums[i+1]);
            }
        }
        int start,end;
        for(int len=3;len<=N;len++)
        {
            for(start=0;start+len<=N;start++)
            {
                end=len+start-1;
                int t1=nums[start]+min(A[start+2][end],A[start+1][end-1]);
                int t2=nums[end] + min(A[start+1][end-1],A[start][end-2]);
                A[start][end]=max(t1,t2);
            }
        }
        int sumA=A[0][N-1];
        int sumB=sum-sumA;
        return (sumA>=sumB);
 
    }
};
