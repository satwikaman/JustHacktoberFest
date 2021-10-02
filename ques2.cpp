// Question Link : https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

// Level : Medium 

class Solution {
public:
    int dp[1001][1001];
    int solve(int e , int f){
        if(e==1){
            return f;
        } 
        if(f==0 || f==1){
            return f;
        }
        
        int mn = INT_MAX;
        for(int k=1;k<=f;k++){
            int l = 0 , r=0 ;
            if(dp[e-1][k-1]!=-1){
                l = dp[e-1][k-1];
            }
            else{
                l = solve(e-1,k-1); dp[e-1][k-1]=l;
            }
            
            if(dp[e][f-k]!=-1){
                r = dp[e][f-k];
            }
            else{
                r = solve(e,f-k); dp[e][f-k]=r;
            }
            int tmp = 1 + max(l,r); 
            mn = min(mn,tmp);
        }
        return dp[e][f]=mn;
        
    }
    int twoEggDrop(int n) {
    memset(dp,-1,sizeof(dp));
    return solve(2,n);
    }
    
};