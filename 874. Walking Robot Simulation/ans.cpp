using namespace std;
#include <vector>
#include <set>
#include <utility>

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {

        int dir = 0; // 0 = north, 1 = east, 2 = south, 3 = west

        vector<pair<int, int> > dir_to_pair;
        dir_to_pair.push_back(make_pair(0, 1));
        dir_to_pair.push_back(make_pair(1, 0));
        dir_to_pair.push_back(make_pair(0, -1));
        dir_to_pair.push_back(make_pair(-1, 0));

        int x = 0, y = 0;

        set<pair<int, int> > obstacles_set;
        for (size_t i = 0; i < obstacles.size(); ++i) {
            obstacles_set.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }

        int max_dist = 0;

        for (size_t i = 0; i < commands.size(); ++i) {
            int cmd = commands[i];
            if (cmd == -2) {
                dir = (dir + 3) % 4; // left
            } else if (cmd == -1) {
                dir = (dir + 1) % 4; // right
            } else {
                int dx = dir_to_pair[dir].first;
                int dy = dir_to_pair[dir].second;

                for (int j = 0; j < cmd; j++) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (obstacles_set.count(make_pair(nx, ny))) {
                        break;
                    }

                    x = nx;
                    y = ny;

                    max_dist = max(max_dist, x * x + y * y);
                }
            }
        }

        return max_dist;
    }
};