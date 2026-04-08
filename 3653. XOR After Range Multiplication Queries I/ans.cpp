#include <vector>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int> >& queries) {
        const int MOD = 1e9 + 7;

        for (int i = 0; i < queries.size(); i++) {
            vector<int>& q = queries[i];

            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = ((long long)nums[idx] * v) % MOD;
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        return ans;
    }
};