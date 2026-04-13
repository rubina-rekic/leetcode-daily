using namespace std;
#include <vector>

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int min=nums.size();
        for(int i=0; i<nums.size(); i++)
            if(nums[i]==target && abs(i-start)<min)
                min=abs(i-start);
            
            return min;
        
    }
};