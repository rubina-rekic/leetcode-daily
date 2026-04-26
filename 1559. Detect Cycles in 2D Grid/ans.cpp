#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > visited;

    bool dfs(vector<vector<char> >& grid, int r, int c, int pr, int pc) {
        visited[r][c] = 1;
        
        // dole
        if (r + 1 < grid.size() && grid[r + 1][c] == grid[r][c]) {
            if (visited[r + 1][c]) {
                if (!(r + 1 == pr && c == pc))
                    return true;
            } else {
                if (dfs(grid, r + 1, c, r, c))
                    return true;
            }
        }

        // gore
        if (r - 1 >= 0 && grid[r - 1][c] == grid[r][c]) {
            if (visited[r - 1][c]) {
                if (!(r - 1 == pr && c == pc))
                    return true;
            } else {
                if (dfs(grid, r - 1, c, r, c))
                    return true;
            }
        }

        // desno
        if (c + 1 < grid[0].size() && grid[r][c + 1] == grid[r][c]) {
            if (visited[r][c + 1]) {
                if (!(r == pr && c + 1 == pc))
                    return true;
            } else {
                if (dfs(grid, r, c + 1, r, c))
                    return true;
            }
        }

        // lijevo
        if (c - 1 >= 0 && grid[r][c - 1] == grid[r][c]) {
            if (visited[r][c - 1]) {
                if (!(r == pr && c - 1 == pc))
                    return true;
            } else {
                if (dfs(grid, r, c - 1, r, c))
                    return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char> >& grid) {
        int m = grid.size();
        int n = grid[0].size();

        visited.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};