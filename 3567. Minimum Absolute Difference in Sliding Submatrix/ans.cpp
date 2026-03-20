using namespace std;
#include <vector>
#include <algorithm>
#include <climits>


class Solution {
public:
    vector<vector<int> > minAbsDiff(vector<vector<int> >& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > ans(m + 1 - k, vector<int>(n - k + 1));

        for (int i = 0; i < m - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {
                vector<int> temp;

                for (int ti = 0; ti < k; ti++)
                    for (int tj = 0; tj < k; tj++)
                        temp.push_back(grid[i + ti][j + tj]);

                sort(temp.begin(), temp.end());
                temp.erase(unique(temp.begin(), temp.end()), temp.end());

                int minDiff = INT_MAX;

                for (int x = 1; x < temp.size(); x++)
                    minDiff = min(minDiff, temp[x] - temp[x - 1]);

                ans[i][j] = (minDiff == INT_MAX) ? 0 : minDiff;
            }
        }
        return ans;
    }
};