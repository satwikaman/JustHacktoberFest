// Question Link : https://leetcode.com/problems/target-sum/

// Level : Medium 

class Solution {
public:
    #define MOD 1000007
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size(),sum=0,w=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }
        w = (sum+target)/2;
        
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
       
        int dp[n+1][w+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(nums[i-1]<= j){
                    dp[i][j] =  (dp[i-1][j] + dp[i-1][j-nums[i-1]]); 
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[n][w];
        
    }
};
