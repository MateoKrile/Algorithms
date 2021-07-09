#include <vector>; 
#include <map>;

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> result_map;
        vector<int> result; 
        for (unsigned int i = 0 ; i<nums.size() ; i++ )
        {
            if(result_map.find(target-nums[i]) != result_map.end())
            {
                result.push_back(nums[i]);
                result.push_back(i);
                return result;
            }
            result_map[target-nums[i]] = i;
        }
        return result;
    }
};