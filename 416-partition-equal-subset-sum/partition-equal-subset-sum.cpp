class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totsum=0;
        for (int i=0;i<n;i++){
            totsum+=nums[i];
        }
        if(totsum%2) return false;
        int k=totsum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];
                dp[i][j]=take|nottake;
            }
        }
        return dp[n-1][k];
    }
};