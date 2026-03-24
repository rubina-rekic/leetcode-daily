using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int> > constructProductMatrix(vector<vector<int> >& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > p(n, vector<int>(m, 0));

        const int MOD = 12345;

        long long iza = 1;

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                p[i][j] = iza, iza = (iza * grid[i][j]) % MOD;

        long long ispred = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                p[i][j] = p[i][j] * ispred % MOD,
                ispred = ispred * grid[i][j] % MOD;

        return p;
    }
};