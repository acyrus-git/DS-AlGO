#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    vector<vector<int>>dp(n,vector<int>(n,0));
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    
	    if(x1==x2 && y1==y2)
	    return 0;
	    queue<pair<int,int>>q;
	    q.push({x1-1,y1-1});
	    while(!q.empty())
	    {
	        int i=q.front().first;
	        int j=q.front().second;
	        q.pop();
	        if(i+1>=0 && i+1<n && j+2>=0 && j+2<n && dp[i+1][j+2]==0)
	        {
	            dp[i+1][j+2]=dp[i][j]+1;
	            q.push({i+1,j+2});
	        }
	        if(i-1>=0 && i-1<n && j+2>=0 && j+2<n && dp[i-1][j+2]==0)
	         {
	            dp[i-1][j+2]=dp[i][j]+1;
	            q.push({i-1,j+2});
	        }
	        if(i-1>=0 && i-1<n && j-2>=0 && j-2<n && dp[i-1][j-2]==0)
	         {
	            dp[i-1][j-2]=dp[i][j]+1;
	            q.push({i-1,j-2});
	        }
	        if(i+1>=0 && i+1<n && j-2>=0 && j-2<n && dp[i+1][j-2]==0)
	         {
	            dp[i+1][j-2]=dp[i][j]+1;
	            q.push({i+1,j-2});
	        }
	        if(i+2>=0 && i+2<n && j+1>=0 && j+1<n && dp[i+2][j+1]==0)
	        {
	            dp[i+2][j+1]=dp[i][j]+1;
	            q.push({i+2,j+1});
	        }
	        if(i-2>=0 && i-2<n && j+1>=0 && j+1<n && dp[i-2][j+1]==0)
	         {
	            dp[i-2][j+1]=dp[i][j]+1;
	            q.push({i-2,j+1});
	        }
	        if(i-2>=0 && i-2<n && j-1>=0 && j-1<n && dp[i-2][j-1]==0)
	         {
	            dp[i-2][j-1]=dp[i][j]+1;
	            q.push({i-2,j-1});
	        }
	        if(i+2>=0 && i+2<n && j-1>=0 && j-1<n && dp[i+2][j-1]==0)
	         {
	            dp[i+2][j-1]=dp[i][j]+1;
	            q.push({i+2,j-1});
	        }
	    }
	    return dp[x2-1][y2-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends