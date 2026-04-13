using namespace std;
#include <vector>
#include <climits>

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int lijevo = INT_MAX;
        int desno = INT_MAX;

        // trazimo lijevo
        for (int i = start; i >= 0; i--) {
            if (nums[i] == target) {
                lijevo = abs(i - start);
                break; 
            }
        }

        // trazimo desno
        for (int i = start; i < n; i++) { 
            if (nums[i] == target) {
                desno = abs(i - start);
                break; // nasli najblizi desno
            }
        }

        return min(lijevo, desno);
    }
};