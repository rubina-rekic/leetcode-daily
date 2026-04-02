#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int> >& coins) {
        int m = coins.size();
        int n = coins[0].size();

        const int temp= INT_MIN;

        // dp[i][j][k]
        vector<vector<vector<int> > > dp(
            m, vector<vector<int> >(n, vector<int>(3, temp)));

        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0]; 
            dp[0][0][1] = 0;          
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 2; k++) {

                    if (i == 0 && j == 0)
                        continue;

                    int best = temp;

                    if (i > 0)
                        best = max(best, dp[i - 1][j][k]);
                    if (j > 0)
                        best = max(best, dp[i][j - 1][k]);

                    if (best != temp) {
                        if (coins[i][j] >= 0) {
                            dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);
                        } else {
                            // bez neutralizacije
                            dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);
                        }
                    }

                    // neutralizacija da ne mozda
                    if (coins[i][j] < 0 && k > 0) {
                        int best_prev = temp;

                        if (i > 0)
                            best_prev = max(best_prev, dp[i - 1][j][k - 1]);
                        if (j > 0)
                            best_prev = max(best_prev, dp[i][j - 1][k - 1]);

                        if (best_prev != temp) {
                            dp[i][j][k] = max(dp[i][j][k], best_prev);
                        }
                    }
                }
            }
        }

        return max(dp[m - 1][n - 1][0], 
                   max(dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]));
    }
};