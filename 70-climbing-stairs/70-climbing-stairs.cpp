class Solution {
public:
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        
        int prev = 1;
        int prev2 = 1;
        for(int i=2;i<=n;i++){
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};