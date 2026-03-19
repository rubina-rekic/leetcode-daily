using namespace std;
#include <vector>;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char> >& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> sumX(n, 0);
        vector<int> sumY(n, 0);

        for (int i = 0; i < m; i++) {
            int numx = 0, numy = 0;

            for (int j = 0; j < n; j++) {

                numx += (grid[i][j] == 'X');
                numy += (grid[i][j] == 'Y');

                sumX[j] += numx, sumY[j] += numy;
                if (sumX[j] == sumY[j] && sumX[j] > 0)
                    res++;
            }
        }

        return res;
    }
    // vidi [X . . ; . Y .]
};