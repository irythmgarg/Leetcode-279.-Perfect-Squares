class Solution {
public:
    int dp[10001]; // Memoization array to store the minimum number of perfect squares for each number up to 10000

    // Recursive function to find the minimum number of perfect square numbers that sum to 'n'
    int hlo(int n)
    {
        // Base cases: 
        // If n is 0 → 0 squares needed; 
        // If n is 1 → only one square needed (1^2)
        if (n == 1 || n == 0)
            return n;

        // If already computed, return stored result
        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;

        // Try all square numbers i*i such that i*i <= n
        for (int i = 1; i * i <= n; i++)
        {
            // Choose square i*i, recursively solve for (n - i*i)
            ans = min(ans, 1 + hlo(n - i * i));
        }

        // Store the result in dp and return
        dp[n] = ans;
        return dp[n];
    }

    int numSquares(int n) {
        // Initialize dp array with -1 to mark uncomputed states
        memset(dp, -1, sizeof(dp));
        
        dp[1] = 1; // Pre-filling known value (1 needs one square: 1^2)

        return hlo(n); // Compute and return result for n
    }
};
