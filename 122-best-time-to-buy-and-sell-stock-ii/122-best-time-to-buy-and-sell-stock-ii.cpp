class Solution {
public:
    int solve(int ind,bool buy,vector<int>& nums,vector<vector<int>>& dp){
        int n = nums.size();
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        int profit = -1e9;
        if(buy){
            profit = max(-nums[ind] + solve(ind+1,0,nums,dp), 0 + solve(ind+1,1,nums,dp));
        }
        else
            profit = max(nums[ind] + solve(ind+1,1,nums,dp), 0 + solve(ind+1,0,nums,dp));
        
        return dp[ind][buy] = profit;
                         
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0),cur(2,0);
        ahead[0] = ahead[1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit = -1e9;
                if(buy){
                    profit = max(-prices[ind] + ahead[0], ahead[1]);
                }
                else{
                    profit = max(prices[ind] + ahead[1], ahead[0]);
                }
                cur[buy] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }
};