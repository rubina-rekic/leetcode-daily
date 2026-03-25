using namespace std;
#include <vector>

class Solution {
public:
    bool canPartitionGrid(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long sum = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                sum += grid[i][j];

        if (sum % 2 != 0)
            return false;

        long long target = sum / 2;

        long long temp_vertical = 0;

        // vertical cut
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                temp_vertical += grid[i][j];
            }
            if (temp_vertical == target)
                return true;
        }

        // horizontal cut

        long long temp_hor = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                temp_hor += grid[i][j];
            }

            if (temp_hor == target)
                return true;
        }

        return false;
    }
};